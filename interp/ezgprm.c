/* RMNLIB - Library of useful routines for C and FORTRAN programming
 * Copyright (C) 1975-2001  Division de Recherche en Prevision Numerique
 *                          Environnement Canada
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation,
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "ezscint.h"
#include "ez_funcdef.h"


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
wordint f77name(ezgprm)(wordint *gdid, char *grtyp, wordint *ni, wordint *nj,
             wordint *ig1, wordint *ig2, wordint *ig3, wordint *ig4)
{
  return c_ezgprm(*gdid, grtyp, ni, nj, ig1, ig2, ig3, ig4);
}

wordint   c_ezgprm(wordint gdid, char *grtyp, wordint *ni, wordint *nj, wordint *ig1, wordint *ig2, wordint *ig3, wordint *ig4)
{
   *grtyp = Grille[gdid].grtyp;
   *ni    = Grille[gdid].ni;
   *nj    = Grille[gdid].nj;
   *ig1   = Grille[gdid].ig[IG1];
   *ig2   = Grille[gdid].ig[IG2];
   *ig3   = Grille[gdid].ig[IG3];
   *ig4   = Grille[gdid].ig[IG4];

   return 0;
}
