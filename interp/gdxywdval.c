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
wordint f77name(gdxywdval)(wordint *gdin, ftnfloat *uuout, ftnfloat *vvout, ftnfloat *uuin, ftnfloat *vvin, ftnfloat *x, ftnfloat *y, wordint *n)
{
   wordint icode;
   
   icode = c_gdxywdval(*gdin, uuout, vvout, uuin, vvin, x, y, *n);
   return icode;

}

wordint c_gdxywdval(wordint gdin, ftnfloat *uuout, ftnfloat *vvout, ftnfloat *uuin, ftnfloat *vvin, ftnfloat *x, ftnfloat *y, wordint n)
{
  wordint ier;

  ftnfloat *tmplat, *tmplon;
  
  tmplat = (ftnfloat *) malloc(n * sizeof(ftnfloat));
  tmplon = (ftnfloat *) malloc(n * sizeof(ftnfloat));
  
  ier = c_gdxyvval(gdin, uuout, vvout, uuin, vvin, x, y, n);
  ier = c_gdllfxy(gdin, tmplat, tmplon, x, y, n);
  ier = c_gdwdfuv(gdin, uuout, vvout, uuout, vvout, tmplat, tmplon, n);
  
  free(tmplat);
  free(tmplon);


  return 0;
}
