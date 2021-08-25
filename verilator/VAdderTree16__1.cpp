// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAdderTree16.h for the primary calling header

#include "VAdderTree16.h"
#include "VAdderTree16__Syms.h"


//--------------------
// Internal Methods

VL_INLINE_OPT void VAdderTree16::_combo__TOP__11(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__11\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			    >> 4U) : (vlTOPp->i_X_0 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			    >> 5U) : (vlTOPp->i_X_0 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			    >> 6U) : (vlTOPp->i_X_0 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			     >> 7U) : (vlTOPp->i_X_0 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			     >> 8U) : (vlTOPp->i_X_0 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			     >> 9U) : (vlTOPp->i_X_0 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			     >> 0xaU) : (vlTOPp->i_X_0 
					 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			      >> 0xbU) : (vlTOPp->i_X_0 
					  >> 0xcU)) 
			 << 0xcU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			      >> 0xcU) : (vlTOPp->i_X_0 
					  >> 0xdU)) 
			 << 0xdU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			      >> 0xdU) : (vlTOPp->i_X_0 
					  >> 0xeU)) 
			 << 0xeU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			      >> 0xeU) : (vlTOPp->i_X_0 
					  >> 0xfU)) 
			 << 0xfU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			       >> 0xfU) : (vlTOPp->i_X_0 
					   >> 0x10U)) 
			  << 0x10U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			       >> 0x10U) : (vlTOPp->i_X_0 
					    >> 0x11U)) 
			  << 0x11U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			       >> 0x11U) : (vlTOPp->i_X_0 
					    >> 0x12U)) 
			  << 0x12U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			       >> 0x12U) : (vlTOPp->i_X_0 
					    >> 0x13U)) 
			  << 0x13U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				>> 0x13U) : (vlTOPp->i_X_0 
					     >> 0x14U)) 
			   << 0x14U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				>> 0x14U) : (vlTOPp->i_X_0 
					     >> 0x15U)) 
			   << 0x15U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				>> 0x15U) : (vlTOPp->i_X_0 
					     >> 0x16U)) 
			   << 0x16U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				>> 0x16U) : (vlTOPp->i_X_0 
					     >> 0x17U)) 
			   << 0x17U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				 >> 0x17U) : (vlTOPp->i_X_0 
					      >> 0x18U)) 
			    << 0x18U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				 >> 0x18U) : (vlTOPp->i_X_0 
					      >> 0x19U)) 
			    << 0x19U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				 >> 0x19U) : (vlTOPp->i_X_0 
					      >> 0x1aU)) 
			    << 0x1aU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				 >> 0x1aU) : (vlTOPp->i_X_0 
					      >> 0x1bU)) 
			    << 0x1bU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				  >> 0x1bU) : (vlTOPp->i_X_0 
					       >> 0x1cU)) 
			     << 0x1cU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				  >> 0x1cU) : (vlTOPp->i_X_0 
					       >> 0x1dU)) 
			     << 0x1dU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				  >> 0x1dU) : (vlTOPp->i_X_0 
					       >> 0x1eU)) 
			     << 0x1eU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				  >> 0x1eU) : (vlTOPp->i_X_0 
					       >> 0x1fU)) 
			     << 0x1fU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
						<< 1U)))));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__12(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__12\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xbU) ^ (0xfffff800U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xcU) ^ (0xfffff000U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xdU) ^ (0xffffe000U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xeU) ^ (0xffffc000U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xfU) ^ (0xffff8000U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x10U) ^ (0xffff0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x11U) ^ (0xfffe0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x12U) ^ (0xfffc0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x13U) ^ (0xfff80000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x14U) ^ (0xfff00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x15U) ^ (0xffe00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x16U) ^ (0xffc00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x17U) ^ (0xff800000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x18U) ^ (0xff000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x19U) ^ (0xfe000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x1aU) ^ (0xfc000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x1bU) ^ (0xf8000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1cU) ^ (0xf0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1dU) ^ (0xe0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1eU) ^ (0xc0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1fU) ^ (0x80000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out
		      : (vlTOPp->i_X_4 >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			 >> 1U) : (vlTOPp->i_X_4 >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			 >> 2U) : (vlTOPp->i_X_4 >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			    >> 3U) : (vlTOPp->i_X_4 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			    >> 4U) : (vlTOPp->i_X_4 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			    >> 5U) : (vlTOPp->i_X_4 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			    >> 6U) : (vlTOPp->i_X_4 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			     >> 7U) : (vlTOPp->i_X_4 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			     >> 8U) : (vlTOPp->i_X_4 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			     >> 9U) : (vlTOPp->i_X_4 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			     >> 0xaU) : (vlTOPp->i_X_4 
					 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			      >> 0xbU) : (vlTOPp->i_X_4 
					  >> 0xcU)) 
			 << 0xcU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			      >> 0xcU) : (vlTOPp->i_X_4 
					  >> 0xdU)) 
			 << 0xdU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			      >> 0xdU) : (vlTOPp->i_X_4 
					  >> 0xeU)) 
			 << 0xeU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			      >> 0xeU) : (vlTOPp->i_X_4 
					  >> 0xfU)) 
			 << 0xfU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			       >> 0xfU) : (vlTOPp->i_X_4 
					   >> 0x10U)) 
			  << 0x10U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			       >> 0x10U) : (vlTOPp->i_X_4 
					    >> 0x11U)) 
			  << 0x11U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			       >> 0x11U) : (vlTOPp->i_X_4 
					    >> 0x12U)) 
			  << 0x12U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__13(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__13\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
			       >> 0x12U) : (vlTOPp->i_X_4 
					    >> 0x13U)) 
			  << 0x13U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				>> 0x13U) : (vlTOPp->i_X_4 
					     >> 0x14U)) 
			   << 0x14U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				>> 0x14U) : (vlTOPp->i_X_4 
					     >> 0x15U)) 
			   << 0x15U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				>> 0x15U) : (vlTOPp->i_X_4 
					     >> 0x16U)) 
			   << 0x16U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				>> 0x16U) : (vlTOPp->i_X_4 
					     >> 0x17U)) 
			   << 0x17U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				 >> 0x17U) : (vlTOPp->i_X_4 
					      >> 0x18U)) 
			    << 0x18U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				 >> 0x18U) : (vlTOPp->i_X_4 
					      >> 0x19U)) 
			    << 0x19U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				 >> 0x19U) : (vlTOPp->i_X_4 
					      >> 0x1aU)) 
			    << 0x1aU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				 >> 0x1aU) : (vlTOPp->i_X_4 
					      >> 0x1bU)) 
			    << 0x1bU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				  >> 0x1bU) : (vlTOPp->i_X_4 
					       >> 0x1cU)) 
			     << 0x1cU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				  >> 0x1cU) : (vlTOPp->i_X_4 
					       >> 0x1dU)) 
			     << 0x1dU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				  >> 0x1dU) : (vlTOPp->i_X_4 
					       >> 0x1eU)) 
			     << 0x1eU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				  >> 0x1eU) : (vlTOPp->i_X_4 
					       >> 0x1fU)) 
			     << 0x1fU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xbU) ^ (0xfffff800U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xcU) ^ (0xfffff000U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xdU) ^ (0xffffe000U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xeU) ^ (0xffffc000U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xfU) ^ (0xffff8000U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x10U) ^ (0xffff0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x11U) ^ (0xfffe0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x12U) ^ (0xfffc0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x13U) ^ (0xfff80000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x14U) ^ (0xfff00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x15U) ^ (0xffe00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x16U) ^ (0xffc00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x17U) ^ (0xff800000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x18U) ^ (0xff000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x19U) ^ (0xfe000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x1aU) ^ (0xfc000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x1bU) ^ (0xf8000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1cU) ^ (0xf0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					    << 1U)))));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__14(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__14\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1dU) ^ (0xe0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1eU) ^ (0xc0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1fU) ^ (0x80000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out
		      : (vlTOPp->i_X_8 >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			 >> 1U) : (vlTOPp->i_X_8 >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			 >> 2U) : (vlTOPp->i_X_8 >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			    >> 3U) : (vlTOPp->i_X_8 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			    >> 4U) : (vlTOPp->i_X_8 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			    >> 5U) : (vlTOPp->i_X_8 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			    >> 6U) : (vlTOPp->i_X_8 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			     >> 7U) : (vlTOPp->i_X_8 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			     >> 8U) : (vlTOPp->i_X_8 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			     >> 9U) : (vlTOPp->i_X_8 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			     >> 0xaU) : (vlTOPp->i_X_8 
					 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			      >> 0xbU) : (vlTOPp->i_X_8 
					  >> 0xcU)) 
			 << 0xcU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			      >> 0xcU) : (vlTOPp->i_X_8 
					  >> 0xdU)) 
			 << 0xdU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			      >> 0xdU) : (vlTOPp->i_X_8 
					  >> 0xeU)) 
			 << 0xeU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			      >> 0xeU) : (vlTOPp->i_X_8 
					  >> 0xfU)) 
			 << 0xfU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			       >> 0xfU) : (vlTOPp->i_X_8 
					   >> 0x10U)) 
			  << 0x10U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			       >> 0x10U) : (vlTOPp->i_X_8 
					    >> 0x11U)) 
			  << 0x11U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			       >> 0x11U) : (vlTOPp->i_X_8 
					    >> 0x12U)) 
			  << 0x12U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
			       >> 0x12U) : (vlTOPp->i_X_8 
					    >> 0x13U)) 
			  << 0x13U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				>> 0x13U) : (vlTOPp->i_X_8 
					     >> 0x14U)) 
			   << 0x14U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				>> 0x14U) : (vlTOPp->i_X_8 
					     >> 0x15U)) 
			   << 0x15U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				>> 0x15U) : (vlTOPp->i_X_8 
					     >> 0x16U)) 
			   << 0x16U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				>> 0x16U) : (vlTOPp->i_X_8 
					     >> 0x17U)) 
			   << 0x17U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				 >> 0x17U) : (vlTOPp->i_X_8 
					      >> 0x18U)) 
			    << 0x18U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				 >> 0x18U) : (vlTOPp->i_X_8 
					      >> 0x19U)) 
			    << 0x19U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				 >> 0x19U) : (vlTOPp->i_X_8 
					      >> 0x1aU)) 
			    << 0x1aU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				 >> 0x1aU) : (vlTOPp->i_X_8 
					      >> 0x1bU)) 
			    << 0x1bU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				  >> 0x1bU) : (vlTOPp->i_X_8 
					       >> 0x1cU)) 
			     << 0x1cU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				  >> 0x1cU) : (vlTOPp->i_X_8 
					       >> 0x1dU)) 
			     << 0x1dU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				  >> 0x1dU) : (vlTOPp->i_X_8 
					       >> 0x1eU)) 
			     << 0x1eU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				  >> 0x1eU) : (vlTOPp->i_X_8 
					       >> 0x1fU)) 
			     << 0x1fU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
		  << 1U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__15(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__15\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xbU) ^ (0xfffff800U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xcU) ^ (0xfffff000U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xdU) ^ (0xffffe000U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xeU) ^ (0xffffc000U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xfU) ^ (0xffff8000U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x10U) ^ (0xffff0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x11U) ^ (0xfffe0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x12U) ^ (0xfffc0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x13U) ^ (0xfff80000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x14U) ^ (0xfff00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x15U) ^ (0xffe00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x16U) ^ (0xffc00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x17U) ^ (0xff800000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x18U) ^ (0xff000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x19U) ^ (0xfe000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x1aU) ^ (0xfc000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x1bU) ^ (0xf8000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1cU) ^ (0xf0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1dU) ^ (0xe0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1eU) ^ (0xc0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1fU) ^ (0x80000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out
		      : (vlTOPp->i_X_12 >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			 >> 1U) : (vlTOPp->i_X_12 >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			 >> 2U) : (vlTOPp->i_X_12 >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			    >> 3U) : (vlTOPp->i_X_12 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			    >> 4U) : (vlTOPp->i_X_12 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			    >> 5U) : (vlTOPp->i_X_12 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			    >> 6U) : (vlTOPp->i_X_12 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			     >> 7U) : (vlTOPp->i_X_12 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			     >> 8U) : (vlTOPp->i_X_12 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			     >> 9U) : (vlTOPp->i_X_12 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			     >> 0xaU) : (vlTOPp->i_X_12 
					 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			      >> 0xbU) : (vlTOPp->i_X_12 
					  >> 0xcU)) 
			 << 0xcU)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__16(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__16\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			      >> 0xcU) : (vlTOPp->i_X_12 
					  >> 0xdU)) 
			 << 0xdU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			      >> 0xdU) : (vlTOPp->i_X_12 
					  >> 0xeU)) 
			 << 0xeU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			   ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			      >> 0xeU) : (vlTOPp->i_X_12 
					  >> 0xfU)) 
			 << 0xfU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			       >> 0xfU) : (vlTOPp->i_X_12 
					   >> 0x10U)) 
			  << 0x10U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			       >> 0x10U) : (vlTOPp->i_X_12 
					    >> 0x11U)) 
			  << 0x11U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			       >> 0x11U) : (vlTOPp->i_X_12 
					    >> 0x12U)) 
			  << 0x12U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			    ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
			       >> 0x12U) : (vlTOPp->i_X_12 
					    >> 0x13U)) 
			  << 0x13U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				>> 0x13U) : (vlTOPp->i_X_12 
					     >> 0x14U)) 
			   << 0x14U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				>> 0x14U) : (vlTOPp->i_X_12 
					     >> 0x15U)) 
			   << 0x15U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				>> 0x15U) : (vlTOPp->i_X_12 
					     >> 0x16U)) 
			   << 0x16U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			     ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				>> 0x16U) : (vlTOPp->i_X_12 
					     >> 0x17U)) 
			   << 0x17U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				 >> 0x17U) : (vlTOPp->i_X_12 
					      >> 0x18U)) 
			    << 0x18U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				 >> 0x18U) : (vlTOPp->i_X_12 
					      >> 0x19U)) 
			    << 0x19U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				 >> 0x19U) : (vlTOPp->i_X_12 
					      >> 0x1aU)) 
			    << 0x1aU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			      ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				 >> 0x1aU) : (vlTOPp->i_X_12 
					      >> 0x1bU)) 
			    << 0x1bU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				  >> 0x1bU) : (vlTOPp->i_X_12 
					       >> 0x1cU)) 
			     << 0x1cU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				  >> 0x1cU) : (vlTOPp->i_X_12 
					       >> 0x1dU)) 
			     << 0x1dU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				  >> 0x1dU) : (vlTOPp->i_X_12 
					       >> 0x1eU)) 
			     << 0x1eU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			       ? (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				  >> 0x1eU) : (vlTOPp->i_X_12 
					       >> 0x1fU)) 
			     << 0x1fU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xbU) ^ (0xfffff800U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xcU) ^ (0xfffff000U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xdU) ^ (0xffffe000U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xeU) ^ (0xffffc000U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			<< 0xfU) ^ (0xffff8000U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
						   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x10U) ^ (0xffff0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x11U) ^ (0xfffe0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x12U) ^ (0xfffc0000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			 << 0x13U) ^ (0xfff80000U & 
				      (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x14U) ^ (0xfff00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					  << 1U)))));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__17(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__17\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x15U) ^ (0xffe00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x16U) ^ (0xffc00000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			  << 0x17U) ^ (0xff800000U 
				       & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x18U) ^ (0xff000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x19U) ^ (0xfe000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x1aU) ^ (0xfc000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			   << 0x1bU) ^ (0xf8000000U 
					& (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					   << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1cU) ^ (0xf0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1dU) ^ (0xe0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1eU) ^ (0xc0000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
			    << 0x1fU) ^ (0x80000000U 
					 & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_0 = 
	(((QData)((IData)((1U & (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
				 >> 0x1fU)))) << 0x20U) 
	 | (QData)((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (1U & (vlTOPp->i_X_0 & (~ vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_1 = 
	(((QData)((IData)((1U & (vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
				 >> 0x1fU)))) << 0x20U) 
	 | (QData)((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
	   | (1U & (vlTOPp->i_X_4 & (~ vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 = 
	(((QData)((IData)((1U & (vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
				 >> 0x1fU)))) << 0x20U) 
	 | (QData)((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
	   | (1U & (vlTOPp->i_X_8 & (~ vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 = 
	(((QData)((IData)((1U & (vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
				 >> 0x1fU)))) << 0x20U) 
	 | (QData)((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
	   | (1U & (vlTOPp->i_X_12 & (~ vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c0_xor_d0 
	= (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 1U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 1U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 2U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 2U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 3U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 3U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 4U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 4U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 5U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 5U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 6U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 6U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 7U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 7U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 8U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 8U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 9U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					     >> 9U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0xaU)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					       >> 0xaU))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0xbU)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					       >> 0xbU))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0xcU)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					       >> 0xcU))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0xdU)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					       >> 0xdU))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0xeU)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					       >> 0xeU))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0xfU)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
					       >> 0xfU))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x10U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x10U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x11U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x11U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x12U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x12U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x13U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x13U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x14U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x14U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x15U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x15U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x16U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x16U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x17U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x17U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x18U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x18U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x19U)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x19U))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_2 
			  >> 0x1aU)) ^ (IData)((vlTOPp->AdderTree16__DOT__csaArray_1_0_i_X_3 
						>> 0x1aU))));
}
