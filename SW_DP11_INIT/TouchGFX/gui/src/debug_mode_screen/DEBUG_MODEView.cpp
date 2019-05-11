#include <gui/debug_mode_screen/DEBUG_MODEView.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern int debug_mode_scroll_sx;
extern int debug_mode_scroll_dx;

DEBUG_MODEView::DEBUG_MODEView()
{

}

void DEBUG_MODEView::setupScreen()
{
		debug_mode_scroll_sx = 3;		//--- indica l'indicatore più in basso
		debug_mode_scroll_dx = 3;
    DEBUG_MODEViewBase::setupScreen();
}

void DEBUG_MODEView::tearDownScreen()
{
    DEBUG_MODEViewBase::tearDownScreen();
}

void DEBUG_MODEView::refreshDebugMode()
{
  DEBUG_MODEView::checkChangeScreen();
	
	touchgfx::Unicode::strncpy( Title1sx, Indicators[debug_mode_scroll_sx - 3].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title2sx, Indicators[debug_mode_scroll_sx - 2].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title3sx, Indicators[debug_mode_scroll_sx - 1].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4sx, Indicators[debug_mode_scroll_sx].NOME, TIT_LEN);

	touchgfx::Unicode::strncpy( Title1dx, Indicators[debug_mode_scroll_dx - 3].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title2dx, Indicators[debug_mode_scroll_dx - 2].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title3dx, Indicators[debug_mode_scroll_dx - 1].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4dx, Indicators[debug_mode_scroll_dx].NOME, TIT_LEN);	
	
	Unicode::snprintf(textIndTitle1sxBuffer, TEXTINDTITLE1SX_SIZE, "%s", Title1sx);	
	Unicode::snprintf(textIndTitle2sxBuffer, TEXTINDTITLE2SX_SIZE, "%s", Title2sx);	
	Unicode::snprintf(textIndTitle3sxBuffer, TEXTINDTITLE3SX_SIZE, "%s", Title3sx);	
	Unicode::snprintf(textIndTitle4sxBuffer, TEXTINDTITLE4SX_SIZE, "%s", Title4sx);	

	Unicode::snprintf(textIndTitle1dxBuffer, TEXTINDTITLE1DX_SIZE, "%s", Title1dx);	
	Unicode::snprintf(textIndTitle2dxBuffer, TEXTINDTITLE2DX_SIZE, "%s", Title2dx);	
	Unicode::snprintf(textIndTitle3dxBuffer, TEXTINDTITLE3DX_SIZE, "%s", Title3dx);	
	Unicode::snprintf(textIndTitle4dxBuffer, TEXTINDTITLE4DX_SIZE, "%s", Title4dx);	
	
//----- Colonna di sinistra
	
	if ( Indicators[debug_mode_scroll_sx - 3].TIPO == INT )
		Unicode::snprintf(textIndValue1sxBuffer, TEXTINDVALUE1SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 3].intValore);
	else
		Unicode::snprintfFloat(textIndValue1sxBuffer, TEXTINDVALUE1SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 3].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx - 2].TIPO == INT )
		Unicode::snprintf(textIndValue2sxBuffer, TEXTINDVALUE2SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 2].intValore);
	else
		Unicode::snprintfFloat(textIndValue2sxBuffer, TEXTINDVALUE2SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 2].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx - 1].TIPO == INT )
		Unicode::snprintf(textIndValue3sxBuffer, TEXTINDVALUE3SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 1].intValore);
	else
		Unicode::snprintfFloat(textIndValue3sxBuffer, TEXTINDVALUE3SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 1].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx].TIPO == INT )
		Unicode::snprintf(textIndValue4sxBuffer, TEXTINDVALUE4SX_SIZE, "%d", Indicators[debug_mode_scroll_sx].intValore);
	else
		Unicode::snprintfFloat(textIndValue4sxBuffer, TEXTINDVALUE4SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx].floatValore);

//----- Colonna di destra
	
	if ( Indicators[debug_mode_scroll_dx - 3].TIPO == INT )
		Unicode::snprintf(textIndValue1dxBuffer, TEXTINDVALUE1DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 3].intValore);
	else
		Unicode::snprintfFloat(textIndValue1dxBuffer, TEXTINDVALUE1DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 3].floatValore);
	
	if ( Indicators[debug_mode_scroll_dx - 2].TIPO == INT )
		Unicode::snprintf(textIndValue2dxBuffer, TEXTINDVALUE2DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 2].intValore);
	else
		Unicode::snprintfFloat(textIndValue2dxBuffer, TEXTINDVALUE2DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 2].floatValore);
	
	if ( Indicators[debug_mode_scroll_dx - 1].TIPO == INT )
		Unicode::snprintf(textIndValue3dxBuffer, TEXTINDVALUE3DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 1].intValore);
	else
		Unicode::snprintfFloat(textIndValue3dxBuffer, TEXTINDVALUE3DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 1].floatValore);
	
	if ( Indicators[debug_mode_scroll_dx].TIPO == INT )
		Unicode::snprintf(textIndValue4dxBuffer, TEXTINDVALUE4DX_SIZE, "%d", Indicators[debug_mode_scroll_dx].intValore);
	else
		Unicode::snprintfFloat(textIndValue4dxBuffer, TEXTINDVALUE4DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx].floatValore);
	
	
	textIndTitle1sx.invalidate();
	textIndTitle2sx.invalidate();
	textIndTitle3sx.invalidate();
	textIndTitle4sx.invalidate();
	textIndTitle1dx.invalidate();
	textIndTitle2dx.invalidate();
	textIndTitle3dx.invalidate();
	textIndTitle4dx.invalidate();
	
	textIndValue1sx.invalidate();
	textIndValue2sx.invalidate();
	textIndValue3sx.invalidate();
	textIndValue4sx.invalidate();
	textIndValue1dx.invalidate();
	textIndValue2dx.invalidate();
	textIndValue3dx.invalidate();
	textIndValue4dx.invalidate();
	
}

void DEBUG_MODEView::checkChangeScreen()
{
	switch ( driveMode ){
				case SETTINGS_MODE	:
					application().gotoSETTINGSScreenNoTransition();
					break;
				case BOARD_DEBUG_MODE	:
					application().gotoBOARD_DEBUGScreenNoTransition();
					break;
				case DEBUG_MODE	:
					
					break;
				case ENDURANCE_MODE	:
					application().gotoENDURANCEScreenNoTransition();
					break;
				case ACCELERATION_MODE	:
					application().gotoACCELERATIONScreenNoTransition();
					break;
				case AUTOX_MODE	:
					application().gotoAUTOCROSSScreenNoTransition();
					break;
				case SKIDPAD_MODE	:
					application().gotoSKIDPADScreenNoTransition();
					break;
	}		
}
