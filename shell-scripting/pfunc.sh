#!/usr/bin/env bash

function getfiles() {
  FILES=`ls -1 | sort | head -10`
}

function showfiles() {
  local COUNT=1
  for FILE in $@
  do
    echo "FILE #$COUNT = $FILE"
    ((COUNT++))
  done
}

getfiles

showfiles $FILES