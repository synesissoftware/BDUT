#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=$Dir/_build

RunMake=1


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    -M|--no-make)

      RunMake=0
      ;;
    --help)

      cat << EOF
BDUT, is a very simple - simplistic, in fact - small, header-only, standalone library for C and C++. Its intent is to be bundled into other projects for which it is not desired to couple to a more sophisticated library.
Copyright (c) 2020-2024, Matthew Wilson and Synesis Information Systems
Runs all (matching) unit-test programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -M
    --no-make
        does not execute CMake and make before running tests


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

status=0

if [ $RunMake -ne 0 ]; then

  echo "Executing make and then running all test programs"

  mkdir -p $CMakeDir || exit 1

  cd $CMakeDir

  if make; then

    :
  else

    status=$?
  fi
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"
  else

    echo "Running all test programs"
  fi

  cd $CMakeDir
fi

if [ $status -eq 0 ]; then

  for f in $(find $Dir -type f '(' -name 'test_unit*' -o -name 'test.unit.*' -o -name 'test_component*' -o -name 'test.component.*' ')' -exec test -x {} \; -print)
  do

    echo
    echo "executing $f:"

    # NOTE: we do not break on fail, because, this being a unit-testing library, some tests actually fail intentionally
    $f
  done
fi

cd ->/dev/null

exit $status


# ############################## end of file ############################# #

