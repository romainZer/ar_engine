#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

info() { echo -e "${BLUE}[INFO]${NC} $1"; }
success() { echo -e "${GREEN}[SUCCESS]${NC} $1"; }
warn() { echo -e "${YELLOW}[WARNING]${NC} $1"; }
error() { echo -e "${RED}[ERROR]${NC} $1"; }

echo -e "${YELLOW}=======================================${NC}"
echo -e "${YELLOW}   AR_ENGINE - Build & Run Script      ${NC}"
echo -e "${YELLOW}=======================================${NC}"

if [ -d "./build" ]; then
    info "Entering existing 'build' directory..."
    cd build || exit
else
    warn "Folder 'build' does not exist. Creating it..."
    mkdir build && cd build || exit
fi

info "Cleaning build artifacts..."
rm -rf ./*

info "Running CMake configuration..."
if cmake ..; then
    success "CMake configuration finished."
else
    error "CMake configuration failed!"
    exit 1
fi

THREADS=$(nproc 2>/dev/null || echo 4)
info "Starting compilation with $THREADS threads..."
if make -j"$THREADS"; then
    success "Compilation successful!"
else
    error "Compilation failed!"
    exit 1
fi

echo -e "${YELLOW}---------------------------------------${NC}"
if [ -f "./ar_engine" ]; then
    info "Starting application: ./ar_engine"
    echo -e "${GREEN}--- APP OUTPUT START ---${NC}"
    ./ar_engine
    echo -e "${GREEN}--- APP OUTPUT END ---${NC}"
else
    error "Executable 'ar_engine' not found!"
    exit 1
fi

success "Script finished execution."