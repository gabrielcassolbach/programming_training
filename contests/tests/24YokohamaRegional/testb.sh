#!/bin/bash

SOLUTION=./b
TEST_DIR=./Test

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Detecta timeout ou gtimeout automaticamente
if command -v timeout >/dev/null 2>&1; then
    TIMEOUT_CMD=timeout
elif command -v gtimeout >/dev/null 2>&1; then
    TIMEOUT_CMD=gtimeout
else
    echo -e "${RED}Erro: 'timeout' ou 'gtimeout' não encontrado. Instale com 'brew install coreutils'.${NC}"
    exit 1
fi

# Verifica permissão de execução
if [ ! -x "$SOLUTION" ]; then
    echo -e "${YELLOW}O arquivo '$SOLUTION' não tem permissão de execução. Corrigindo...${NC}"
    chmod +x "$SOLUTION"
fi

# Loop de testes
for input in "$TEST_DIR"/*.in; do
    base=$(basename "$input" .in)
    expected="$TEST_DIR/$base.ans"

    echo -n "Running test $base... "

    # Executa com timeout de 1 segundo
    $TIMEOUT_CMD 1s $SOLUTION < "$input" > out.txt
    EXIT_CODE=$?

    if [ $EXIT_CODE -eq 124 ]; then
        echo -e "${YELLOW}Time Limit Exceeded${NC}"
        continue
    elif [ $EXIT_CODE -ne 0 ]; then
        echo -e "${RED}Runtime Error (exit code $EXIT_CODE)${NC}"
        continue
    fi

    # Compara saída ignorando espaços em branco no final
    cmp -s out.txt "$expected"
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
