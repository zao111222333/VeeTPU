// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAdderTree16.h for the primary calling header

#include "VAdderTree16.h"
#include "VAdderTree16__Syms.h"


//--------------------
// Internal Methods

VL_INLINE_OPT void VAdderTree16::_combo__TOP__34(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__34\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_1 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_0 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_1 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_0 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_1 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[0U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[0U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[1U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[1U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[2U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[2U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[3U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__3__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[3U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__3__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[4U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__4__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[4U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__4__KET____DOT__u_csla_unit__o_sum_1;
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__35(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__35\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[5U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__5__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[5U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__5__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[6U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__6__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[6U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__6__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[7U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[7U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__7__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[8U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[8U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__8__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0[9U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_0;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1[9U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__9__KET____DOT__u_csla_unit__o_sum_1;
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[0U] 
	= ((8U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_rca))
	    ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [0U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [0U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[1U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [0U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [1U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [1U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[2U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [1U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [2U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [2U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[3U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [2U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [3U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [3U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[4U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [3U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [4U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [4U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[5U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [4U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [5U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [5U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[6U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [5U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [6U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [6U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[7U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [6U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [7U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [7U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[8U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [7U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [8U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [8U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel[9U] 
	= ((8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [8U]) ? vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_1
	   [9U] : vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_0
	   [9U]);
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3ffffff8U & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (7U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	      [0U]));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3fffffc7U & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0x38U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
		       [1U] << 3U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3ffffe3fU & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0x1c0U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			[2U] << 6U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3ffff1ffU & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0xe00U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			[3U] << 9U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3fff8fffU & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0x7000U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			 [4U] << 0xcU)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3ffc7fffU & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0x38000U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			  [5U] << 0xfU)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3fe3ffffU & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0x1c0000U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			   [6U] << 0x12U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3f1fffffU & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0xe00000U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			   [7U] << 0x15U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x38ffffffU & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0x7000000U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			    [8U] << 0x18U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x7ffffffU & vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
	   | (0x38000000U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			     [9U] << 0x1bU)));
    vlTOPp->o_S = (((QData)((IData)((1U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
					   [9U] >> 3U)))) 
		    << 0x23U) | (((QData)((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel)) 
				  << 5U) | (QData)((IData)(
							   ((0x1cU 
							     & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_rca) 
								<< 2U)) 
							    | (3U 
							       & (IData)(vlTOPp->AdderTree16__DOT__S___05F0)))))));
}

void VAdderTree16::_eval(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_eval\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->_combo__TOP__5(vlSymsp);
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->_combo__TOP__7(vlSymsp);
    vlTOPp->_combo__TOP__8(vlSymsp);
    vlTOPp->_combo__TOP__9(vlSymsp);
    vlTOPp->_combo__TOP__10(vlSymsp);
    vlTOPp->_combo__TOP__11(vlSymsp);
    vlTOPp->_combo__TOP__12(vlSymsp);
    vlTOPp->_combo__TOP__13(vlSymsp);
    vlTOPp->_combo__TOP__14(vlSymsp);
    vlTOPp->_combo__TOP__15(vlSymsp);
    vlTOPp->_combo__TOP__16(vlSymsp);
    vlTOPp->_combo__TOP__17(vlSymsp);
    vlTOPp->_combo__TOP__18(vlSymsp);
    vlTOPp->_combo__TOP__19(vlSymsp);
    vlTOPp->_combo__TOP__20(vlSymsp);
    vlTOPp->_combo__TOP__21(vlSymsp);
    vlTOPp->_combo__TOP__22(vlSymsp);
    vlTOPp->_combo__TOP__23(vlSymsp);
    vlTOPp->_combo__TOP__24(vlSymsp);
    vlTOPp->_combo__TOP__25(vlSymsp);
    vlTOPp->_combo__TOP__26(vlSymsp);
    vlTOPp->_combo__TOP__27(vlSymsp);
    vlTOPp->_combo__TOP__28(vlSymsp);
    vlTOPp->_combo__TOP__29(vlSymsp);
    vlTOPp->_combo__TOP__30(vlSymsp);
    vlTOPp->_combo__TOP__31(vlSymsp);
    vlTOPp->_combo__TOP__32(vlSymsp);
    vlTOPp->_combo__TOP__33(vlSymsp);
    vlTOPp->_combo__TOP__34(vlSymsp);
    vlTOPp->_combo__TOP__35(vlSymsp);
}

VL_INLINE_OPT QData VAdderTree16::_change_request(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_change_request\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VAdderTree16::_change_request_1(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_change_request_1\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	       [0U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	       [0U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [1U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [1U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [2U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [2U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [3U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [3U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [4U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [4U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [5U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [5U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [6U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [6U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [7U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [7U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [8U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [8U])
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [9U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
	    [9U])
	|| (vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_0)
	|| (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0)
	|| (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1));
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [0U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [0U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [1U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [1U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [2U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [2U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [3U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [3U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [4U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [4U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [5U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [5U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [6U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [6U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [7U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [7U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [8U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [8U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [9U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [9U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/CSLA.v:22\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/cpa.v:13: AdderTree16.csla_1.u_cpa.carry_pord\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[0].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[0].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[1].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[1].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[2].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[2].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[3].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[3].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[4].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[4].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[5].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[5].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[6].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[6].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[7].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[7].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[8].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[8].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:10: AdderTree16.csla_1.csla_unit[9].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/VeeTPU/./src/main/verilog/veetpu/ip/csla/csla_unit.v:11: AdderTree16.csla_1.csla_unit[9].u_csla_unit.carry_1\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[0U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[0U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[1U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[1U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[2U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[2U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[3U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[3U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[4U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[4U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[5U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[5U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[6U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[6U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[7U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[7U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[8U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[8U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel[9U] 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	[9U];
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__3__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__4__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__5__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__6__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__7__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__8__KET____DOT__u_csla_unit__DOT__carry_1;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_0;
    vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1 
	= vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__9__KET____DOT__u_csla_unit__DOT__carry_1;
    return __req;
}

#ifdef VL_DEBUG
void VAdderTree16::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
}
#endif // VL_DEBUG
