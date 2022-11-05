      subroutine iri_driver_sub( jmag, alati, along, iyyyy, mmdd,
     1    dhour, heibeg, heiend, heistp,outf)
          implicit none

          logical jf(50),print_output
          real alati,along,dhour,heibeg,heiend,heistp
          real oarr(100,1000)
          real outf(20,1000)
          integer jmag,k
          integer mmdd,iyyyy

          !call read_ig_rz
          !call readapf107

c          print_output = .true.

          do k=1,50
              jf(k) = .true.
          enddo
!jf(4,5,6,21,23,28,29,30,33,35,39,40,47)=.false. all others .true.
          jf(4)  = .false.
          jf(5)  = .false.
          jf(6)  = .false.
         jf(21) = .false.
         jf(23) = .false.
          jf(28) = .false.
          jf(29) = .false.
         jf(30) = .false.
          jf(33) = .false.
          jf(35) = .false.
          jf(39) = .false.
          jf(40) = .false.
          jf(47) = .false.
c          jmag = 0
c          alati = 37.8
c          along = 75.4
c          iyyyy = 2021
c          mmdd = 0303
c          dhour = 12.
c          heibeg = 100.
c          heiend = 600.
c          heistp = 50.
c               call read_ig_rz
c       call readapf107
c
c Programs using subroutine IRI_WEB need to include (see IRITEST.FOR):
c
         ! do i=1,100
         ! oarr(i,1)=-1.0
         ! enddo
          call read_ig_rz
          call readapf107

          do k=1,100
          oarr(k,1)=-1.0
          enddo
          call iri_sub(jf,jmag,alati,along,iyyyy,mmdd,dhour,
     &               heibeg,heiend,heistp,outf,oarr)

c          num = (heiend-heibeg)/heistp
c          print *,'     h/km        d/e           Tn           Ti    
c     1      Te         d/O+          d/H+        d/HE+         d/O2+
c     1   d/NO+r'  
c             do col=1, num
c                write(*,100) col*heistp,(outf(row,col),row=1,9)
c             enddo
c  100        format(10(1x,E12.6))
          RETURN
          END
