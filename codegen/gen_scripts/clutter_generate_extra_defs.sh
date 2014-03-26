#!/bin/bash

# The script assumes that it resides in the tools/gen_scripts directory
# and the defs files will be placed in clutter/src.
# It shall be executed from the tools/gen_scripts directory.

# To update the clutter_signals.defs file:
# 1. ./clutter_generate_extra_defs.sh
#    Generates clutter/src/clutter_signals.defs.orig and clutter/src/clutter_signals.defs.
#    If any hunks from the patch file fail to apply, apply them manually to the
#    clutter_signals.defs file, if required.
# 2. Optional: Remove clutter/src/clutter_signals.defs.orig.

# To update the clutter_signals.defs file and the patch file:
# 1. Like step 1 when updating only the clutter_signals.defs file.
# 2. Apply new patches manually to the clutter_signals.defs file.
# 3. ./clutter_generate_extra_defs.sh --make-patch
# 4. Like step 2 when updating only the clutter_signals.defs file.

ROOT_DIR="$(dirname "$0")/../.."
GEN_DIR="$ROOT_DIR/codegen/extradefs"
OUT_DIR="$ROOT_DIR/clutter/src"
OUT_DEFS_FILE="$OUT_DIR"/clutter_signals.defs

if [ $# -eq 0 ]
then
  # Without LC_ALL=C documentation (docs "xxx") may be translated in the .defs file.
  LC_ALL=C "$GEN_DIR"/generate_extra_defs > "$OUT_DEFS_FILE"
  #PATCH_OPTIONS="--backup --version-control=simple --suffix=.orig"
  #patch $PATCH_OPTIONS "$OUT_DEFS_FILE" "$OUT_DEFS_FILE".patch
elif [ "$1" = "--make-patch" ]
then
  diff --unified=10 "$OUT_DEFS_FILE".orig "$OUT_DEFS_FILE" > "$OUT_DEFS_FILE".patch
else
  echo "Usage: $0 [--make-patch]"
  exit 1
fi

