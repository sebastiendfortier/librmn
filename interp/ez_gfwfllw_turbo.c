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

void  c_gfwfllw_turbo(ftnfloat *uullout, ftnfloat *vvllout, ftnfloat *latin, ftnfloat *lonin,
                  ftnfloat *xlatingf, ftnfloat *xloningf, ftnfloat *uvcart, ftnfloat *xyz,
                  ftnfloat *sinlat, ftnfloat *sinlon, ftnfloat *coslat, ftnfloat *coslon,
                  ftnfloat *sinlatp, ftnfloat *sinlonp, ftnfloat *coslatp, ftnfloat *coslonp,
                  ftnfloat *r, ftnfloat *ri,
                  wordint *ni, wordint *nj,
                  char *grtyp, wordint *ig1, wordint *ig2, wordint *ig3, wordint *ig4)
{
   wordint zero = 0;
   wordint npts = *ni * *nj;
   wordint trois = 3;
   char grtypl[2];

   grtypl[0] = 'L';
   f77name(ez_gdwfllw)(uullout,vvllout,lonin,ni,nj,grtypl, &zero, &zero, &zero, &zero, 1);

   f77name(ez_uvacart_turbo)(xyz, uullout, vvllout, sinlatp, sinlonp, coslatp, coslonp, ni, nj);
   f77name(mxm)(r, &trois, xyz, &trois, uvcart, &npts);
   f77name(ez_cartauv_turbo)(uullout, vvllout, uvcart, sinlat, sinlon, coslat, coslon, ni, nj);
}


