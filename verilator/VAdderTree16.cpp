// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAdderTree16.h for the primary calling header

#include "VAdderTree16.h"
#include "VAdderTree16__Syms.h"


//--------------------


void VAdderTree16::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAdderTree16::eval\n"); );
    VAdderTree16__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VAdderTree16::_eval_initial_loop(VAdderTree16__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VAdderTree16::_combo__TOP__1(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__1\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c0_xor_d0 
	= (1U & (vlTOPp->i_X_2 ^ vlTOPp->i_X_3));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0xbU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0xcU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0xdU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0xeU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0xfU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x10U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x11U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x12U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x13U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x14U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x15U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x16U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x17U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x18U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x19U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x1aU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x1bU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x1cU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x1dU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x1eU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_2 ^ vlTOPp->i_X_3) >> 0x1fU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c0_xor_d0 
	= (1U & (vlTOPp->i_X_6 ^ vlTOPp->i_X_7));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0xbU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0xcU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0xdU));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__2(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__2\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0xeU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0xfU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x10U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x11U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x12U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x13U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x14U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x15U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x16U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x17U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x18U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x19U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x1aU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x1bU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x1cU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x1dU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x1eU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_6 ^ vlTOPp->i_X_7) >> 0x1fU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c0_xor_d0 
	= (1U & (vlTOPp->i_X_10 ^ vlTOPp->i_X_11));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0xbU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0xcU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0xdU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0xeU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0xfU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x10U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x11U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x12U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x13U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x14U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x15U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x16U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x17U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x18U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x19U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x1aU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x1bU));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__3(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__3\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x1cU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x1dU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x1eU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_10 ^ vlTOPp->i_X_11) 
		 >> 0x1fU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c0_xor_d0 
	= (1U & (vlTOPp->i_X_14 ^ vlTOPp->i_X_15));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0xbU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0xcU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0xdU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0xeU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0xfU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x10U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x11U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x12U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x13U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x14U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x15U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x16U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x17U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x18U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x19U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x1aU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x1bU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x1cU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x1dU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x1eU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & ((vlTOPp->i_X_14 ^ vlTOPp->i_X_15) 
		 >> 0x1fU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum) 
	 | (1U & ((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c0_xor_d0)
		     ? vlTOPp->i_X_1 : vlTOPp->i_X_3)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 1U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_1 >> 1U) : (vlTOPp->i_X_3 
						 >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 2U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_1 >> 2U) : (vlTOPp->i_X_3 
						 >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 3U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_1 >> 3U) : (vlTOPp->i_X_3 
						 >> 3U)) 
		    << 3U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__4(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__4\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 4U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_1 >> 4U) : 
			(vlTOPp->i_X_3 >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 5U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_1 >> 5U) : 
			(vlTOPp->i_X_3 >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 6U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_1 >> 6U) : 
			(vlTOPp->i_X_3 >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 7U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_1 >> 7U) : 
			(vlTOPp->i_X_3 >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 8U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_1 >> 8U) : 
			 (vlTOPp->i_X_3 >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 9U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_1 >> 9U) : 
			 (vlTOPp->i_X_3 >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0xaU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_1 >> 0xaU)
			  : (vlTOPp->i_X_3 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0xbU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_1 >> 0xbU)
			  : (vlTOPp->i_X_3 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0xcU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_1 >> 0xcU)
			   : (vlTOPp->i_X_3 >> 0xcU)) 
			 << 0xcU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0xdU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_1 >> 0xdU)
			   : (vlTOPp->i_X_3 >> 0xdU)) 
			 << 0xdU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0xeU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_1 >> 0xeU)
			   : (vlTOPp->i_X_3 >> 0xeU)) 
			 << 0xeU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0xfU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_1 >> 0xfU)
			   : (vlTOPp->i_X_3 >> 0xfU)) 
			 << 0xfU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x10U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_1 >> 0x10U)
			    : (vlTOPp->i_X_3 >> 0x10U)) 
			  << 0x10U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x11U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_1 >> 0x11U)
			    : (vlTOPp->i_X_3 >> 0x11U)) 
			  << 0x11U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x12U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_1 >> 0x12U)
			    : (vlTOPp->i_X_3 >> 0x12U)) 
			  << 0x12U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x13U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_1 >> 0x13U)
			    : (vlTOPp->i_X_3 >> 0x13U)) 
			  << 0x13U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x14U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_1 >> 0x14U)
			     : (vlTOPp->i_X_3 >> 0x14U)) 
			   << 0x14U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x15U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_1 >> 0x15U)
			     : (vlTOPp->i_X_3 >> 0x15U)) 
			   << 0x15U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__5(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__5\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x16U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_1 >> 0x16U)
			     : (vlTOPp->i_X_3 >> 0x16U)) 
			   << 0x16U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x17U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_1 >> 0x17U)
			     : (vlTOPp->i_X_3 >> 0x17U)) 
			   << 0x17U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x18U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_1 >> 0x18U)
			      : (vlTOPp->i_X_3 >> 0x18U)) 
			    << 0x18U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x19U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_1 >> 0x19U)
			      : (vlTOPp->i_X_3 >> 0x19U)) 
			    << 0x19U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x1aU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_1 >> 0x1aU)
			      : (vlTOPp->i_X_3 >> 0x1aU)) 
			    << 0x1aU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x1bU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_1 >> 0x1bU)
			      : (vlTOPp->i_X_3 >> 0x1bU)) 
			    << 0x1bU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x1cU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_1 >> 0x1cU)
			       : (vlTOPp->i_X_3 >> 0x1cU)) 
			     << 0x1cU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x1dU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_1 >> 0x1dU)
			       : (vlTOPp->i_X_3 >> 0x1dU)) 
			     << 0x1dU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x1eU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_1 >> 0x1eU)
			       : (vlTOPp->i_X_3 >> 0x1eU)) 
			     << 0x1eU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_0 ^ vlTOPp->i_X_1) >> 0x1fU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
	   | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_1 >> 0x1fU)
			       : (vlTOPp->i_X_3 >> 0x1fU)) 
			     << 0x1fU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum) 
	 | (1U & ((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c0_xor_d0)
		     ? vlTOPp->i_X_5 : vlTOPp->i_X_7)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 1U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_5 >> 1U) : (vlTOPp->i_X_7 
						 >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 2U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_5 >> 2U) : (vlTOPp->i_X_7 
						 >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 3U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_5 >> 3U) : (vlTOPp->i_X_7 
						 >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 4U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_5 >> 4U) : 
			(vlTOPp->i_X_7 >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 5U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_5 >> 5U) : 
			(vlTOPp->i_X_7 >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 6U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_5 >> 6U) : 
			(vlTOPp->i_X_7 >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 7U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_5 >> 7U) : 
			(vlTOPp->i_X_7 >> 7U)) << 7U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__6(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__6\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 8U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_5 >> 8U) : 
			 (vlTOPp->i_X_7 >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 9U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_5 >> 9U) : 
			 (vlTOPp->i_X_7 >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0xaU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_5 >> 0xaU)
			  : (vlTOPp->i_X_7 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0xbU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_5 >> 0xbU)
			  : (vlTOPp->i_X_7 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0xcU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_5 >> 0xcU)
			   : (vlTOPp->i_X_7 >> 0xcU)) 
			 << 0xcU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0xdU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_5 >> 0xdU)
			   : (vlTOPp->i_X_7 >> 0xdU)) 
			 << 0xdU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0xeU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_5 >> 0xeU)
			   : (vlTOPp->i_X_7 >> 0xeU)) 
			 << 0xeU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0xfU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_5 >> 0xfU)
			   : (vlTOPp->i_X_7 >> 0xfU)) 
			 << 0xfU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x10U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_5 >> 0x10U)
			    : (vlTOPp->i_X_7 >> 0x10U)) 
			  << 0x10U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x11U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_5 >> 0x11U)
			    : (vlTOPp->i_X_7 >> 0x11U)) 
			  << 0x11U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x12U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_5 >> 0x12U)
			    : (vlTOPp->i_X_7 >> 0x12U)) 
			  << 0x12U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x13U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_5 >> 0x13U)
			    : (vlTOPp->i_X_7 >> 0x13U)) 
			  << 0x13U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x14U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_5 >> 0x14U)
			     : (vlTOPp->i_X_7 >> 0x14U)) 
			   << 0x14U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x15U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_5 >> 0x15U)
			     : (vlTOPp->i_X_7 >> 0x15U)) 
			   << 0x15U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x16U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_5 >> 0x16U)
			     : (vlTOPp->i_X_7 >> 0x16U)) 
			   << 0x16U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x17U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_5 >> 0x17U)
			     : (vlTOPp->i_X_7 >> 0x17U)) 
			   << 0x17U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x18U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_5 >> 0x18U)
			      : (vlTOPp->i_X_7 >> 0x18U)) 
			    << 0x18U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x19U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_5 >> 0x19U)
			      : (vlTOPp->i_X_7 >> 0x19U)) 
			    << 0x19U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__7(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__7\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x1aU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_5 >> 0x1aU)
			      : (vlTOPp->i_X_7 >> 0x1aU)) 
			    << 0x1aU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x1bU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_5 >> 0x1bU)
			      : (vlTOPp->i_X_7 >> 0x1bU)) 
			    << 0x1bU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x1cU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_5 >> 0x1cU)
			       : (vlTOPp->i_X_7 >> 0x1cU)) 
			     << 0x1cU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x1dU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_5 >> 0x1dU)
			       : (vlTOPp->i_X_7 >> 0x1dU)) 
			     << 0x1dU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x1eU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_5 >> 0x1eU)
			       : (vlTOPp->i_X_7 >> 0x1eU)) 
			     << 0x1eU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_4 ^ vlTOPp->i_X_5) >> 0x1fU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
	   | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_5 >> 0x1fU)
			       : (vlTOPp->i_X_7 >> 0x1fU)) 
			     << 0x1fU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum) 
	 | (1U & ((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c0_xor_d0)
		     ? vlTOPp->i_X_9 : vlTOPp->i_X_11)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 1U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_9 >> 1U) : (vlTOPp->i_X_11 
						 >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 2U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_9 >> 2U) : (vlTOPp->i_X_11 
						 >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 3U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_9 >> 3U) : (vlTOPp->i_X_11 
						 >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 4U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_9 >> 4U) : 
			(vlTOPp->i_X_11 >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 5U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_9 >> 5U) : 
			(vlTOPp->i_X_11 >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 6U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_9 >> 6U) : 
			(vlTOPp->i_X_11 >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 7U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_9 >> 7U) : 
			(vlTOPp->i_X_11 >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 8U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_9 >> 8U) : 
			 (vlTOPp->i_X_11 >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 9U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_9 >> 9U) : 
			 (vlTOPp->i_X_11 >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0xaU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_9 >> 0xaU)
			  : (vlTOPp->i_X_11 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0xbU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_9 >> 0xbU)
			  : (vlTOPp->i_X_11 >> 0xbU)) 
			<< 0xbU)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__8(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__8\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0xcU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_9 >> 0xcU)
			   : (vlTOPp->i_X_11 >> 0xcU)) 
			 << 0xcU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0xdU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_9 >> 0xdU)
			   : (vlTOPp->i_X_11 >> 0xdU)) 
			 << 0xdU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0xeU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_9 >> 0xeU)
			   : (vlTOPp->i_X_11 >> 0xeU)) 
			 << 0xeU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0xfU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_9 >> 0xfU)
			   : (vlTOPp->i_X_11 >> 0xfU)) 
			 << 0xfU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x10U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_9 >> 0x10U)
			    : (vlTOPp->i_X_11 >> 0x10U)) 
			  << 0x10U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x11U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_9 >> 0x11U)
			    : (vlTOPp->i_X_11 >> 0x11U)) 
			  << 0x11U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x12U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_9 >> 0x12U)
			    : (vlTOPp->i_X_11 >> 0x12U)) 
			  << 0x12U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x13U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_9 >> 0x13U)
			    : (vlTOPp->i_X_11 >> 0x13U)) 
			  << 0x13U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x14U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_9 >> 0x14U)
			     : (vlTOPp->i_X_11 >> 0x14U)) 
			   << 0x14U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x15U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_9 >> 0x15U)
			     : (vlTOPp->i_X_11 >> 0x15U)) 
			   << 0x15U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x16U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_9 >> 0x16U)
			     : (vlTOPp->i_X_11 >> 0x16U)) 
			   << 0x16U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x17U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_9 >> 0x17U)
			     : (vlTOPp->i_X_11 >> 0x17U)) 
			   << 0x17U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x18U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_9 >> 0x18U)
			      : (vlTOPp->i_X_11 >> 0x18U)) 
			    << 0x18U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x19U) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_9 >> 0x19U)
			      : (vlTOPp->i_X_11 >> 0x19U)) 
			    << 0x19U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x1aU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_9 >> 0x1aU)
			      : (vlTOPp->i_X_11 >> 0x1aU)) 
			    << 0x1aU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x1bU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_9 >> 0x1bU)
			      : (vlTOPp->i_X_11 >> 0x1bU)) 
			    << 0x1bU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x1cU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_9 >> 0x1cU)
			       : (vlTOPp->i_X_11 >> 0x1cU)) 
			     << 0x1cU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x1dU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_9 >> 0x1dU)
			       : (vlTOPp->i_X_11 >> 0x1dU)) 
			     << 0x1dU)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__9(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__9\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x1eU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_9 >> 0x1eU)
			       : (vlTOPp->i_X_11 >> 0x1eU)) 
			     << 0x1eU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_8 ^ vlTOPp->i_X_9) >> 0x1fU) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
	   | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_9 >> 0x1fU)
			       : (vlTOPp->i_X_11 >> 0x1fU)) 
			     << 0x1fU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum) 
	 | (1U & ((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffffffeU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c0_xor_d0)
		     ? vlTOPp->i_X_13 : vlTOPp->i_X_15)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 1U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_13 >> 1U) : (vlTOPp->i_X_15 
						  >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 2U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_13 >> 2U) : (vlTOPp->i_X_15 
						  >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 3U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? (vlTOPp->i_X_13 >> 3U) : (vlTOPp->i_X_15 
						  >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 4U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_13 >> 4U) : 
			(vlTOPp->i_X_15 >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 5U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffffffdfU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_13 >> 5U) : 
			(vlTOPp->i_X_15 >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 6U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffffffbfU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_13 >> 6U) : 
			(vlTOPp->i_X_15 >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 7U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffffff7fU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? (vlTOPp->i_X_13 >> 7U) : 
			(vlTOPp->i_X_15 >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 8U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffffeffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_13 >> 8U) : 
			 (vlTOPp->i_X_15 >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 9U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffffdffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_13 >> 9U) : 
			 (vlTOPp->i_X_15 >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0xaU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffffbffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_13 >> 0xaU)
			  : (vlTOPp->i_X_15 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0xbU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffff7ffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? (vlTOPp->i_X_13 >> 0xbU)
			  : (vlTOPp->i_X_15 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0xcU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffffefffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x1000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__11__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_13 >> 0xcU)
			   : (vlTOPp->i_X_15 >> 0xcU)) 
			 << 0xcU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0xdU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffffdfffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x2000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__12__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_13 >> 0xdU)
			   : (vlTOPp->i_X_15 >> 0xdU)) 
			 << 0xdU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0xeU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffffbfffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x4000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__13__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_13 >> 0xeU)
			   : (vlTOPp->i_X_15 >> 0xeU)) 
			 << 0xeU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0xfU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffff7fffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x8000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__14__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			   ? (vlTOPp->i_X_13 >> 0xfU)
			   : (vlTOPp->i_X_15 >> 0xfU)) 
			 << 0xfU)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__10(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__10\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x10U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffeffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x10000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__15__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_13 >> 0x10U)
			    : (vlTOPp->i_X_15 >> 0x10U)) 
			  << 0x10U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x11U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffdffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x20000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__16__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_13 >> 0x11U)
			    : (vlTOPp->i_X_15 >> 0x11U)) 
			  << 0x11U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x12U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfffbffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x40000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__17__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_13 >> 0x12U)
			    : (vlTOPp->i_X_15 >> 0x12U)) 
			  << 0x12U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x13U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfff7ffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x80000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__18__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			    ? (vlTOPp->i_X_13 >> 0x13U)
			    : (vlTOPp->i_X_15 >> 0x13U)) 
			  << 0x13U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x14U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffefffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x100000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__19__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_13 >> 0x14U)
			     : (vlTOPp->i_X_15 >> 0x14U)) 
			   << 0x14U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x15U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffdfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x200000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__20__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_13 >> 0x15U)
			     : (vlTOPp->i_X_15 >> 0x15U)) 
			   << 0x15U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x16U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xffbfffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x400000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__21__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_13 >> 0x16U)
			     : (vlTOPp->i_X_15 >> 0x16U)) 
			   << 0x16U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x17U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xff7fffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x800000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__22__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			     ? (vlTOPp->i_X_13 >> 0x17U)
			     : (vlTOPp->i_X_15 >> 0x17U)) 
			   << 0x17U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x18U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfeffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x1000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__23__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_13 >> 0x18U)
			      : (vlTOPp->i_X_15 >> 0x18U)) 
			    << 0x18U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x19U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfdffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x2000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__24__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_13 >> 0x19U)
			      : (vlTOPp->i_X_15 >> 0x19U)) 
			    << 0x19U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x1aU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xfbffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x4000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__25__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_13 >> 0x1aU)
			      : (vlTOPp->i_X_15 >> 0x1aU)) 
			    << 0x1aU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x1bU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xf7ffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x8000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__26__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			      ? (vlTOPp->i_X_13 >> 0x1bU)
			      : (vlTOPp->i_X_15 >> 0x1bU)) 
			    << 0x1bU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x1cU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xefffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x10000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__27__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_13 >> 0x1cU)
			       : (vlTOPp->i_X_15 >> 0x1cU)) 
			     << 0x1cU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x1dU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xdfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x20000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__28__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_13 >> 0x1dU)
			       : (vlTOPp->i_X_15 >> 0x1dU)) 
			     << 0x1dU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x1eU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0xbfffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x40000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__29__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_13 >> 0x1eU)
			       : (vlTOPp->i_X_15 >> 0x1eU)) 
			     << 0x1eU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & (((vlTOPp->i_X_12 ^ vlTOPp->i_X_13) 
		  >> 0x1fU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x7fffffffU & vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
	   | (0x80000000U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__30__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			       ? (vlTOPp->i_X_13 >> 0x1fU)
			       : (vlTOPp->i_X_15 >> 0x1fU)) 
			     << 0x1fU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffffffdU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out
		      : (vlTOPp->i_X_0 >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffffffbU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			 >> 1U) : (vlTOPp->i_X_0 >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xfffffff7U & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			 >> 2U) : (vlTOPp->i_X_0 >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0xffffffefU & vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? (vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
			    >> 3U) : (vlTOPp->i_X_0 
				      >> 4U)) << 4U)));
}
