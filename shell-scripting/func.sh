#!/usr/bin/env bash

function hello() {
  local LNAME=$1
  echo "hello $LNAME"
}

goodbye() {
  echo "goodbye $1"
}

hello bob

goodbye angela

exit 0