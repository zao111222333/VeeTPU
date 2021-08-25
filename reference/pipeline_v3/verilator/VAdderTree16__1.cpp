// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAdderTree16.h for the primary calling header

#include "VAdderTree16.h"
#include "VAdderTree16__Syms.h"


//--------------------
// Internal Methods

VL_INLINE_OPT void VAdderTree16::_combo__TOP__9(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__9\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			    >> 3U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			    >> 4U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			    >> 5U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			    >> 6U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			     >> 7U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			     >> 8U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
			     >> 9U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out) 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT___zz_5 = ((0x400U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
						  >> 1U)) 
				       | (0x3ffU & 
					  ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum) 
					   >> 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xffeU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		    & (~ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)))));
    vlTOPp->AdderTree16__DOT___zz_7 = ((0x400U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
				       | (0x3ffU & 
					  ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum) 
					   >> 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		    & (~ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c0_xor_d0 
	= (1U & ((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_7) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
		      >> 1U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c0_xor_d0)
		     ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			>> 1U) : (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 1U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 2U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 2U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 3U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			 >> 3U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
				   >> 2U)) << 2U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__10(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__10\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 3U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 4U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			 >> 4U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 4U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 5U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			    >> 5U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 5U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 6U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			    >> 6U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 6U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 7U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			    >> 7U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 7U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 8U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			    >> 8U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 8U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 9U)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 9U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 9U) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 0xaU)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 0xaU) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
					 >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		   >> 0xaU) ^ ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			       >> 0xbU)) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
			     >> 0xbU) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry) 
					 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)
		      : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
			 >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			    >> 3U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			    >> 4U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			    >> 5U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			    >> 6U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			     >> 7U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			     >> 8U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
			     >> 9U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out)) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum = 
	((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__S___05F0 = ((0x2000U 
					   & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0__DOT__c_out) 
					      << 3U)) 
					  | (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum) 
					      << 2U) 
					     | ((2U 
						 & (((0xfffffffeU 
						      & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
						     ^ 
						     ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
						      << 1U)) 
						    ^ 
						    ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum) 
						     << 1U))) 
						| (1U 
						   & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)))));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__11(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__11\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT___zz_5) 
		    & (~ (IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_sum)))));
    vlTOPp->AdderTree16__DOT__S___05F1 = (((IData)(vlTOPp->AdderTree16__DOT__csaArray_2_0_o_carry) 
					   << 1U) | 
					  (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum) 
						   >> 1U) 
						  & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
						     | (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum))) 
						 | ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry) 
						    & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__sum_pord 
	= ((6U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__sum_pord)) 
	   | (1U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		     >> 2U) ^ (IData)(vlTOPp->AdderTree16__DOT__S___05F1))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__1__KET____DOT__Fadd_1__DOT__a 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 3U) ^ ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			    >> 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__2__KET____DOT__Fadd_1__DOT__a 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 4U) ^ ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			    >> 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord 
	= ((6U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord)) 
	   | (1U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		     >> 2U) & (IData)(vlTOPp->AdderTree16__DOT__S___05F1))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 5U) ^ ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			    >> 3U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 8U) ^ ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			    >> 6U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 0xbU) ^ ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			      >> 9U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 5U) & ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			    >> 3U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 5U) | ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			    >> 3U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 8U) & ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			    >> 6U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 8U) | ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			    >> 6U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 0xbU) & ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			      >> 9U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1 
	= (7U & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
		  >> 0xbU) | ((IData)(vlTOPp->AdderTree16__DOT__S___05F1) 
			      >> 9U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__1__KET____DOT__Fadd_1__DOT__c 
	= ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord) 
	   & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__1__KET____DOT__Fadd_1__DOT__a));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__2__KET____DOT__Fadd_1__DOT__c 
	= (((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord) 
	    >> 1U) & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__2__KET____DOT__Fadd_1__DOT__a));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__sum_pord 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__sum_pord)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__1__KET____DOT__Fadd_1__DOT__a) 
		     ^ (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__sum_pord 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__sum_pord)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__2__KET____DOT__Fadd_1__DOT__a) 
		     << 2U) ^ (0xfffffffcU & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord) 
					      << 1U)))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xeU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xeU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (1U & (~ (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xeU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xeU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (1U & (~ (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xeU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xeU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (1U & (~ (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((6U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((6U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((6U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((6U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((6U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((6U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord)) 
	   | (2U & ((0x3ffffffeU & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
				     >> 2U) & (IData)(vlTOPp->AdderTree16__DOT__S___05F1))) 
		    | ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__1__KET____DOT__Fadd_1__DOT__c) 
		       << 1U))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord)) 
	   | (4U & ((0x3ffffffcU & (((IData)(vlTOPp->AdderTree16__DOT__S___05F0) 
				     >> 2U) & (IData)(vlTOPp->AdderTree16__DOT__S___05F1))) 
		    | ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__FullAdd__BRA__2__KET____DOT__Fadd_1__DOT__c) 
		       << 2U))));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_rca 
	= ((8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord) 
		  << 1U)) | (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__sum_pord));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1) 
		    << 1U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__12(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__12\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__0__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__1__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_0)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((5U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1 
	= ((3U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_or_i_X_1) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_and_i_X_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1 
	= ((7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (8U & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xdU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (2U & (((1U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 1U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
				       >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1 
	= ((0xbU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT____Vcellout__csla_unit__BRA__2__KET____DOT__u_csla_unit__o_sum_1)) 
	   | (4U & (((2U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1))
		      ? (~ ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
			    >> 2U)) : ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__i_X_0_xor_i_X_1) 
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
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x1f8U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel)) 
	   | (7U & vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
	      [0U]));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x1c7U & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel)) 
	   | (0x38U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
		       [1U] << 3U)));
    vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel 
	= ((0x3fU & (IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel)) 
	   | (0x1c0U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			[2U] << 6U)));
    vlTOPp->o_S = ((0x4000U & (vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [2U] << 0xbU)) | (((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__out_sel) 
						  << 5U) 
						 | ((0x1cU 
						     & ((IData)(vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_rca) 
							<< 2U)) 
						    | (3U 
						       & (IData)(vlTOPp->AdderTree16__DOT__S___05F0)))));
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
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0)
	 | (vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1));
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [0U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [0U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/CSLA.v:24\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [1U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [1U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/CSLA.v:24\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [2U] ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__o_sum_sel
			       [2U]))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/CSLA.v:24\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__u_cpa__DOT__carry_pord))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/cpa.v:13: AdderTree16.csla_1.u_cpa.carry_pord\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/csla_unit.v:10: AdderTree16.csla_1.csla_unit[0].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__0__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/csla_unit.v:11: AdderTree16.csla_1.csla_unit[0].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/csla_unit.v:10: AdderTree16.csla_1.csla_unit[1].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__1__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/csla_unit.v:11: AdderTree16.csla_1.csla_unit[1].u_csla_unit.carry_1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_0))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/csla_unit.v:10: AdderTree16.csla_1.csla_unit[2].u_csla_unit.carry_0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1 ^ vlTOPp->__Vchglast__TOP__AdderTree16__DOT__csla_1__DOT__csla_unit__BRA__2__KET____DOT__u_csla_unit__DOT__carry_1))) VL_DBG_MSGF("        CHANGE: /Accelerator/pipeline_v3/./src/main/scala/fp/basic/csla/verilog/csla_unit.v:11: AdderTree16.csla_1.csla_unit[2].u_csla_unit.carry_1\n"); );
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
    return __req;
}

#ifdef VL_DEBUG
void VAdderTree16::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_X_0 & 0xf800U))) {
	Verilated::overWidthError("i_X_0");}
    if (VL_UNLIKELY((i_X_1 & 0xf800U))) {
	Verilated::overWidthError("i_X_1");}
    if (VL_UNLIKELY((i_X_2 & 0xf800U))) {
	Verilated::overWidthError("i_X_2");}
    if (VL_UNLIKELY((i_X_3 & 0xf800U))) {
	Verilated::overWidthError("i_X_3");}
    if (VL_UNLIKELY((i_X_4 & 0xf800U))) {
	Verilated::overWidthError("i_X_4");}
    if (VL_UNLIKELY((i_X_5 & 0xf800U))) {
	Verilated::overWidthError("i_X_5");}
    if (VL_UNLIKELY((i_X_6 & 0xf800U))) {
	Verilated::overWidthError("i_X_6");}
    if (VL_UNLIKELY((i_X_7 & 0xf800U))) {
	Verilated::overWidthError("i_X_7");}
    if (VL_UNLIKELY((i_X_8 & 0xf800U))) {
	Verilated::overWidthError("i_X_8");}
    if (VL_UNLIKELY((i_X_9 & 0xf800U))) {
	Verilated::overWidthError("i_X_9");}
    if (VL_UNLIKELY((i_X_10 & 0xf800U))) {
	Verilated::overWidthError("i_X_10");}
    if (VL_UNLIKELY((i_X_11 & 0xf800U))) {
	Verilated::overWidthError("i_X_11");}
    if (VL_UNLIKELY((i_X_12 & 0xf800U))) {
	Verilated::overWidthError("i_X_12");}
    if (VL_UNLIKELY((i_X_13 & 0xf800U))) {
	Verilated::overWidthError("i_X_13");}
    if (VL_UNLIKELY((i_X_14 & 0xf800U))) {
	Verilated::overWidthError("i_X_14");}
    if (VL_UNLIKELY((i_X_15 & 0xf800U))) {
	Verilated::overWidthError("i_X_15");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
}
#endif // VL_DEBUG
