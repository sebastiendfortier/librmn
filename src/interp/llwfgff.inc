!/* RMNLIB - Library of useful routines for C and FORTRAN programming
! * Copyright (C) 1975-2001  Division de Recherche en Prevision Numerique
! *                          Environnement Canada
! *
! * This library is free software; you can redistribute it and/or
! * modify it under the terms of the GNU Lesser General Public
! * License as published by the Free Software Foundation,
! * version 2.1 of the License.
! *
! * This library is distributed in the hope that it will be useful,
! * but WITHOUT ANY WARRANTY; without even the implied warranty of
! * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
! * Lesser General Public License for more details.
! *
! * You should have received a copy of the GNU Lesser General Public
! * License along with this library; if not, write to the
! * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
! * Boston, MA 02111-1307, USA.
! */
!**s/p gfw2llw - converts from u-v (grid) wind grid components to
!                U(east-west) and V(north-south) components 
!
      subroutine llwfgff(uu,vv,xlat,xlon,li,lj,grtyp,ig1,ig2,ig3,ig4)

      implicit none
      integer li,lj
      real uu(li,lj), vv(li,lj), xlat(li,lj),xlon(li,lj)
      character*1 grtyp
      integer ig1,ig2,ig3,ig4
      external cigaxg
!
!auteur- y. chartier - april 94
!
!langage- fortran
!
!objet(gfw2llw)
!     - passe de vent de grille (composantes u et v)
!     - aux composantes u(est-ouest), v(nord-sud)
!
!librairies
!
!appel- call gfw2llw(uu,psi,li,lj,iyp,xg1,xg2,xg3,xg4)
!
!modules- xgaig
!
!arguments
!     in/out - uu   - a l'entree contient la composante u
!     a la sortie la composante u est-ouest
!     in/out - vv   - a l'entree contient la composante v
!     a la sortie la composante v nord-sud
!     in    - li    - premiere dimension des champs uu et vv
!     in    - lj    - deuxieme dimension des champs uu et vv
!     in    - igtyp  - type de grille (voir ouvrir)
!     in    - xg1   - ** descripteur de grille (reel),
!     in    - xg2   -    igtyp = 'n', pi, pj, d60, dgrw
!     in    - xg3   -    igtyp = 'l', lat0, lon0, dlat, dlon,
!     in    - xg4   -    igtyp = 'a', 'b', 'g', xg1 = 0. global,
!                                                   = 1. nord
!                                                   = 2. sud **
!
!messages- "erreur mauvaise grille (gfw2llw)"
!
!-------------------------------------------------------------
!
      real r(3,3),ri(3,3)
!

      real xlat1,xlon1,xlat2,xlon2
      real :: xlatgf(li,lj),xlongf(li,lj)
      real :: uvcart(3, li, lj), xyz(3, li, lj)


      call cigaxg(grtyp,xlat1,xlon1,xlat2,xlon2,ig1,ig2,ig3,ig4)
      call ez_crot( r, ri, xlon1, xlat1, xlon2, xlat2 )
      call ez_gfxyfll(xlon,xlat,xlongf,xlatgf,li*lj,      xlat1,xlon1,xlat2,xlon2)
      call ez_vrotf2(uu,vv,xlon,xlat,xlongf,xlatgf,ri,xyz,uvcart,li,lj)

      return
      end
