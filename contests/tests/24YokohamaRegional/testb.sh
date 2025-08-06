#!/bin/bash

SOLUTION=./b
TEST_DIR=./B

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

for input in "$TEST_DIR"/*.in; do
    base=$(basename "$input" .in)
    expected="$TEST_DIR/$base.ans"

    echo -n "Running test $base... "

    # Run with timeout of 1 second
    timeout 1s $SOLUTION < "$input" > out.txt
    EXIT_CODE=$?

    if [ $EXIT_CODE -eq 124 ]; then
        echo -e "${YELLOW}Time Limit Exceeded${NC}"
        continue
    elif [ $EXIT_CODE -ne 0 ]; then
        echo -e "${RED}Runtime Error (exit code $EXIT_CODE)${NC}"
        continue
    fi

    # Compare outputs ignoring trailing whitespace
    diff -Z -q out.txt "$expected" > /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}Wrong Answer${NC}"
        echo ">>> Input:"
        cat "$input"
        echo ">>> Expected:"
        cat "$expected"
        echo ">>> Got:"
        cat out.txt
        break
    fi
done
