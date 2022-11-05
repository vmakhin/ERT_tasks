/* iri_driver_main.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

#include <stdio.h>
//#include <stdlib.h>
#include "gnuplot_i.h"
#include <unistd.h>
//int usleep(useconds_t usec);
#define SLEEP_LGTH  2
#define NPOINTS     50

gnuplot_ctrl    *   h1,
                    *   h2,
                    *   h3,
                    *   h4 ;
double              x[NPOINTS] ;
double              y[NPOINTS] ;
/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;

/* Main program */ int MAIN__(void)
{
    /* Format strings */
    static char fmt_101[] = "(10(1x,e12.6))";
    static char fmt_100[] = "(10(1x,e12.6))";

    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i,col, num, row, jmag, mmdd;
    static real outf[20000]	/* was [20][1000] */, alati, along, dhour;
    static integer iyyyy;
    static real heibeg, heiend, heistp;
    extern /* Subroutine */ int iri_driver_sub__(integer *, real *, real *, 
	    integer *, integer *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 6, 0, fmt_101, 0 };
    static cilist io___13 = { 0, 6, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_100, 0 };


    jmag = 0;
    alati = 37.8f;
    along = 75.4f;
    iyyyy = 2021;
    mmdd = 303;
    dhour = 12.f;
    heibeg = 60.f;
    heiend = 600.f;
    heistp = 10.f;
    s_wsfe(&io___10);
    do_fio(&c__1, (char *)&alati, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&along, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&dhour, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&heibeg, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&heiend, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&heistp, (ftnlen)sizeof(real));
    e_wsfe();
    iri_driver_sub__(&jmag, &alati, &along, &iyyyy, &mmdd, &dhour, &heibeg, &
	    heiend, &heistp, outf);
    num = (heiend - heibeg) / heistp;
  //  s_wsle(&io___13);
  //  do_lio(&c__9, &c__1, "     h/km        d/e           Tn           Ti   "
//	    " \r        Te         d/O+          d/H+        d/HE+         d/"
//	    "O2+\r      d/NO+r", (ftnlen)128);
 //   e_wsle();
    i__1 = num;
    for (col = 1; col <= i__1; ++col) {
//	s_wsfe(&io___15);
	r__1 = heibeg + (col-1) * heistp;
//	do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
            x[col] = (double)r__1;
            y[col] = (double)outf[1 + col * 20 - 21];
//	for (row = 1; row <= 9; ++row) {
//	    do_fio(&c__1, (char *)&outf[row + col * 20 - 21], (ftnlen)sizeof(
//		    real));
//	}
//	e_wsfe();
    }

    /*
     * Initialize the gnuplot handle
     */
    printf("*** example of gnuplot control through C ***\n") ;
    h1 = gnuplot_init() ;
    gnuplot_cmd(h1, "set terminal png");
    gnuplot_cmd(h1, "set output \"NevsH.png\"");
    printf("*** user-defined lists of points\n");
    gnuplot_setstyle(h1, "points") ;
    // set logscale for density, xaxis
    gnuplot_cmd(h1, "set logscale x 10") ;
    // set range of xaxis 
    gnuplot_cmd(h1, "set xrange [1.E10:1.E12]") ; 
    // set axes labels 
    gnuplot_set_xlabel(h1, "Ne,1/m^3") ;
    gnuplot_set_ylabel(h1, "Altitude, km") ;
    gnuplot_plot_xy(h1, y, x, NPOINTS, "Ne vs Altitude") ;
    sleep(10);
    //pause mouse close;

    printf("*** end of gnuplot example\n") ;
// to close chart type q on keyboard or close chart using X
// in the right top corner of chart
//    gnuplot_cmd(h1, "pause mouse close") ; 
    gnuplot_close(h1) ;
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* Main program alias */ int irimain_ () { MAIN__ (); return 0; }
