// Copyright (c) 2014 David Munger, Pierre L'Ecuyer, Université de Montréal.  
// Copyright (c) 2012 Richard Simard, Pierre L'Ecuyer, Université de Montréal. 
// 
// This file is part of Lattice Builder. 
// 
// Lattice Builder is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version. 
// 
// Lattice Builder is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
// 
// You should have received a copy of the GNU General Public License 
// along with Lattice Builder.  If not, see <http://www.gnu.org/licenses/>. 
// 
// 
// Converted from tcode to Doxygen in 2014.

/**
 * 
 * 
 * This module contains global constants used in
 * LatMRG{} and Lattice Builder.
 * 
 * \note Richard: Most of these are used only in
 * LatMRG; thus should separate this in two different files:
 * one common and one in LatMRG.
 * 
 * 
 * 
 * 
 */

#ifndef CONST_H
#define CONST_H

#include <string>


namespace LatCommon {


/**
 * Indicates which norm is used to measure the length of vectors.
 * For \f$X = (x_1,\dots,x_t)\f$,\c SUPNORM corresponds to \f$\Vert X\Vert = \max (|x_1|,\dots,|x_t|)\f$.\\f[1ex]
 * \c L1NORM  corresponds to \f$\Vert X\Vert = |x_1|+\cdots+|x_t|\f$.\\f[1ex]
 * \c L2NORM corresponds to  \f$\Vert X\Vert = (x_1^2+\cdots+x_t^2)^{1/2}\f$.\\f[1ex]
 * \c ZAREMBANORM corresponds
 * to  \f$\Vert X\Vert = \max(1, |x_1|)\cdots\max(1, |x_t|)\f$.
 */
enum NormType { SUPNORM, L1NORM, L2NORM, ZAREMBANORM };


/**
 * Used to identify the type of a generator. If a generator is of type \c MWC,
 * it is converted to its corresponding \c MRG by the program.\c LCG: the linear congruential generator.\\f[1ex]
 * \c MRG: the multiple-recursive generator.\\f[1ex]
 * \c MWC: the multiply-with-carry generator.\\f[1ex]
 * \c KOROBOV: the Korobov lattice.\\f[1ex]
 * \c RANK1: the rank 1 lattice.
 */
enum GenType { LCG, MRG, MWC, KOROBOV, RANK1 };

   
/**
 * Indicates whether to analyze the lattice generated by all possible states,
 * or a sub-lattice generated by the set of recurrent states or by a
 * sub-cycle of the generator.\c FULL: The complete lattice, generated by all possible
 * initial states, will be analyzed.\\f[1ex]
 * \c RECURRENT: If the (combined) generator has transient
 * states, then the lattice analyzed will be the sub-lattice generated by
 * the set of recurrent states.\\f[1ex]
 * \c ORBIT: The grid generated by the (forward) orbit of
 * a state of the (combined) generator is analyzed. This state
 * is specified as follows.
 * On the following \f$J\f$ lines, the initial state for each
 * component must be given. This is an integer vector with a number
 * of components equal to the order of the component.\\f[1ex]
 * \c PRIMEPOWER: In the case where some component is an MLCG
 * whose modulus is a power of a prime \f$p\f$, then the states visited over
 * a single orbit (sub-cycle) of that component generate a sub-lattice
 * (when \f$a \equiv 1 \bmod{p}\f$) or belong to the union of
 * \f$p-1\f$ sub-lattices (otherwise).  If \c LatticeType takes this value,
 * and a component is a MLCG (\f$k=1\f$),
 * and if the modulus of that MLCG is given
 * in the data file in the form (b): \f$(x\ y\ z)\f$ with \f$z=0\f$ and \f$x\f$ prime,
 * then what is analyzed
 * is one of those sub-lattices.  This is done by dividing the modulus
 * by the appropriate power of \f$p\f$, as described in \cite rLEC94e .
 * For example, if \f$p=2\f$ and \f$a \mod 8 = 5\f$, then the modulus is divided
 * by 4 as in \cite rFIS90a, \cite rKNU81a .
 */
enum LatticeType { FULL, RECURRENT, ORBIT, PRIMEPOWER };

          
/**
 * Indicates whether an integer is prime, probably prime, composite or its
 * status is unknown (or don't care).
 */
enum PrimeType { UNKNOWN, PRIME, PROB_PRIME, COMPOSITE };

          
/**
 * Given an integer \f$r\f$, indicates what to do about the decomposition of \f$r\f$ in
 * its prime factors.\c DECOMP: means that the program will factorize \f$r\f$.\\f[1ex]
 * \c DECOMP_WRITE: means that the program will factorize \f$r\f$ and
 * writes the factors in a file.\\f[1ex]
 * \c DECOMP_READ: means that \f$r\f$ is already factorized, and
 * the factors will be read from a file.\\f[1ex]
 * \c DECOMP_PRIME: means that \f$r\f$ is prime.
 * No factorization will be done.
 */
enum DecompType { DECOMP, DECOMP_WRITE, DECOMP_READ, DECOMP_PRIME };


/**
 * Indicates in which form and where the results will be sent. <tt>co:output</tt>\c TERMINAL: the results will appear only on the terminal screen.\\f[1ex]
 * \c RES: the results will be in plain text format and sent to a file with
 * extension ``\c .res''.\\f[1ex]
 * \c TEX:  the results will be in \f$\mbox{\LaTeX}\f$ format and sent to a file with
 * extension ``\c .tex''.\\f[1ex]
 * \c GEN:  the results will be sent to a file with
 * extension ``\c .gen''.
 */
enum OutputType { TERMINAL, RES, TEX, GEN };


/**
 * Gives the merit criterion for ranking generators or lattices.\c BEYER: the figure of merit is the Beyer quotient \f$Q_T\f$.\\f[1ex]
 * \c SPECTRAL: the figure of merit \f$S_T\f$ is based on the spectral test.\\f[1ex]
 * \c PALPHA: the figure of merit is based on \f$P_\alpha\f$.\\f[1ex]
 * \c BOUND_JS: the figure of merit is based on the Joe-Sinescu bound
 * \cite rSIN08a .
 */
enum CriterionType { SPECTRAL, BEYER, PALPHA, BOUND_JS };


/**
 * Indicates which normalization is used to compute
 * \f$S_t\f$ in the spectral test, for each dimension \f$t\f$.\c BESTLAT: the value used for \f$d_t^*\f$ corresponds to
 * the best lattice.\\f[1ex]
 * \c LAMINATED: the value used for \f$d_t^*\f$ corresponds to
 * the best \e emph lattice.\\f[1ex]
 * \c ROGERS:  the value for \f$d_t^*\f$ is obtained from <em>emph</em> bound
 * on the density of sphere packing.\\f[1ex]
 * \c MINKOWSKI: the value for \f$d_t^*\f$ is obtained from <em>emph</em>
 * theoretical bounds on the length of the shortest nonzero vector in the lattice
 * using the \f${\cal L}_2\f$ norm.\\f[1ex]
 * \c MINKL1: the value for \f$d_t^*\f$ is obtained from the theoretical bounds on
 * the length of the shortest nonzero vector in the lattice using the \f${\cal L}_1\f$
 * norm.\\f[1ex]
 * \c PALPHA_N: the case of the \f$P_\alpha\f$ test.\\f[1ex]
 * \c NORMA_GENERIC: the trivial normalization (= 1) used for the generic
 * case when no useful normalization constant is known.
 */
enum NormaType { BESTLAT, LAMINATED, ROGERS, MINKOWSKI, MINKL1,
                 PALPHA_N, NORMA_GENERIC };


/**
 * Indicates which type of calculation is considered for the \f$P_\alpha\f$ test.
 * <tt>CalcType.def</tt>\c PAL is for the \f$P_\alpha\f$ test. \\f[1ex]
 * \c BAL is for the bound on the \f$P_\alpha\f$ test. \\f[1ex]
 * \c NORMPAL is for the \f$P_\alpha\f$ test \c PAL, with the result
 * normalized over the \c BAL bound. \\f[1ex]
 * \c SEEKPAL is for the \f$P_\alpha\f$ seek, which searches for good values
 * of the multiplier.
 */
enum CalcType { PAL, NORMPAL, BAL, SEEKPAL };


/**
 * Indicates which type of conditions are imposed
 * on the coefficients \f$a_i\f$ of a recurrence.\c NO_COND:  no condition is imposed on the coefficients.\\f[1ex]
 * \c APP_FACT: the coefficients must satisfy the ``approximate factoring''
 * condition \f$|a_i| (m\mod |a_i|) < m\f$. Congruential generators are easier to
 * implement under this condition \cite rLEC90a .\\f[1ex]
 * \c POWER_TWO: the coefficients must be sums or differences of powers
 * of 2.\\f[1ex]
 * \c EQUAL_COEF: all the coefficients must be equal by groups:
 * a first group all equal to a first number, a second group all equal to a
 * second number, and so on. \\f[1ex]
 * \c ZERO_COEF: all the coefficients must be equal to 0, except for a
 * select fews.
 */
enum ImplemCond { NO_COND, APP_FACT, POWER_TWO, EQUAL_COEF, ZERO_COEF };


/**
 * Indicates the search method used to find good multipliers \f$a_i\f$.\c EXHAUST:  the search will be exhaustive over the chosen regions.\\f[1ex]
 * \c RANDOM:  the search will be random over the chosen regions.
 */
enum SearchMethod { EXHAUST, RANDOM };
/**
 * @}
 * \name toString functions
 * @{
 * 
 * Useful functions for printing the \c enum constants in this module.
 */

/**
 * Returns the \c enum constants in this module as strings.
 * \note Richard: These are global methods for now, but maybe \c Const should be a
 * class containing these methods.
 */
std::string toStringNorm (NormType);
std::string toStringGen (GenType);
std::string toStringLattice (LatticeType);
std::string toStringPrime (PrimeType);
std::string toStringDecomp (DecompType);
std::string toStringOutput (OutputType);
std::string toStringCriterion (CriterionType);
std::string toStringNorma (NormaType);
std::string toStringCalc (CalcType);
std::string toStringImplemCond (ImplemCond);
std::string toStringSearchMethod (SearchMethod);

}

#endif

