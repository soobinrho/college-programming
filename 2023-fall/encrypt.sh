#!/bin/sh

# ---------------------------------------------------------------------
# Encrypt every file.
# ---------------------------------------------------------------------
find . -type f -not -name "encrypt" -not -name "*.gpg" -not -name "*.lock" -not -name "README.md" -not -name "encrypt.sh" | xargs gpg -v --batch --yes --recipient soobinrho@gmail.com --encrypt-files

# ---------------------------------------------------------------------
# Run this whenever a change has been made.
# ---------------------------------------------------------------------
# gpg -v --batch --yes --recipient soobinrho@gmail.com --encrypt <fileName>
