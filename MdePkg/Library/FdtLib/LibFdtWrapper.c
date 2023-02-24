/** @file
  Root include file of C runtime library to support building the third-party
  libfdt library.

  Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "LibFdtSupport.h"
#include <Library/DebugLib.h>

char *
strchr (
  const char  *s,
  int         c
  )
{
  char  pattern[2];

  pattern[0] = (CHAR8)c;
  pattern[1] = 0;
  return AsciiStrStr (s, pattern);
}

char *
strrchr (
  const char  *s,
  int         c
  )
{

  char  pattern[2];
  CONST CHAR8  *LastMatch;
  CONST CHAR8  *StringTmp;
  CONST CHAR8  *SearchString;

  pattern[0] = (CHAR8)c;
  pattern[1] = 0;
  SearchString = pattern;

  //
  // ASSERT both strings are less long than PcdMaximumAsciiStringLength
  //
  ASSERT (AsciiStrSize (s) != 0);
  ASSERT (AsciiStrSize (SearchString) != 0);

  if (*SearchString == '\0') {
    return (CHAR8 *)s;
  }

  LastMatch = NULL;
  do {
    StringTmp = AsciiStrStr(s, SearchString);

    if (StringTmp == NULL) {
      break;
    }

    LastMatch = StringTmp;
    s = StringTmp + 1;
  } while (s != NULL);

  return (CHAR8 *)LastMatch;
}

unsigned long
strtoul (
  const char  *nptr,
  char        **endptr,
  int         base
  )
{
  RETURN_STATUS  Status;
  UINTN          ReturnValue;

  ASSERT (base == 10 || base == 16);

  if (base == 10) {
    Status = AsciiStrDecimalToUintnS (nptr, endptr, &ReturnValue);
  } else if (base == 16) {
    Status = AsciiStrHexToUintnS (nptr, endptr, &ReturnValue);
  } else {
    Status = RETURN_INVALID_PARAMETER;
  }

  if (RETURN_ERROR (Status)) {
    return MAX_UINTN;
  }

  return ReturnValue;
}
