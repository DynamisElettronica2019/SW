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
		debug_mode_scroll_sx = N_DEBUG_MODE_VALUES - 1;		//--- indica l'indicatore più in basso
		debug_mode_scroll_dx = N_DEBUG_MODE_VALUES - 1;
    DEBUG_MODEViewBase::setupScreen();
}

void DEBUG_MODEView::tearDownScreen()
{
    DEBUG_MODEViewBase::tearDownScreen();
}

void DEBUG_MODEView::refreshDebugMode()
{
  DEBUG_MODEView::checkChangeScreen();
	
	touchgfx::Unicode::strncpy( Title1sx, Indicators[debug_mode_scroll_sx - 7].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title2sx, Indicators[debug_mode_scroll_sx - 6].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title3sx, Indicators[debug_mode_scroll_sx - 5].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4sx, Indicators[debug_mode_scroll_sx - 4].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title5sx, Indicators[debug_mode_scroll_sx - 3].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title6sx, Indicators[debug_mode_scroll_sx - 2].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title7sx, Indicators[debug_mode_scroll_sx - 1].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title8sx, Indicators[debug_mode_scroll_sx].NOME, TIT_LEN);	

	touchgfx::Unicode::strncpy( Title1dx, Indicators[debug_mode_scroll_dx - 7].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title2dx, Indicators[debug_mode_scroll_dx - 6].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title3dx, Indicators[debug_mode_scroll_dx - 5].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4dx, Indicators[debug_mode_scroll_dx - 4].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title5dx, Indicators[debug_mode_scroll_dx - 3].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title6dx, Indicators[debug_mode_scroll_dx - 2].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title7dx, Indicators[debug_mode_scroll_dx - 1].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title8dx, Indicators[debug_mode_scroll_dx].NOME, TIT_LEN);	
	
	Unicode::snprintf(textIndTitle1sxBuffer, TEXTINDTITLE1SX_SIZE, "%s", Title1sx);	
	Unicode::snprintf(textIndTitle2sxBuffer, TEXTINDTITLE2SX_SIZE, "%s", Title2sx);	
	Unicode::snprintf(textIndTitle3sxBuffer, TEXTINDTITLE3SX_SIZE, "%s", Title3sx);	
	Unicode::snprintf(textIndTitle4sxBuffer, TEXTINDTITLE4SX_SIZE, "%s", Title4sx);	
	Unicode::snprintf(textIndTitle5sxBuffer, TEXTINDTITLE5SX_SIZE, "%s", Title5sx);
	Unicode::snprintf(textIndTitle6sxBuffer, TEXTINDTITLE6SX_SIZE, "%s", Title6sx);	
	Unicode::snprintf(textIndTitle7sxBuffer, TEXTINDTITLE7SX_SIZE, "%s", Title7sx);	
	Unicode::snprintf(textIndTitle8sxBuffer, TEXTINDTITLE8SX_SIZE, "%s", Title8sx);
	
	Unicode::snprintf(textIndTitle1dxBuffer, TEXTINDTITLE1DX_SIZE, "%s", Title1dx);	
	Unicode::snprintf(textIndTitle2dxBuffer, TEXTINDTITLE2DX_SIZE, "%s", Title2dx);	
	Unicode::snprintf(textIndTitle3dxBuffer, TEXTINDTITLE3DX_SIZE, "%s", Title3dx);	
	Unicode::snprintf(textIndTitle4dxBuffer, TEXTINDTITLE4DX_SIZE, "%s", Title4dx);	
	Unicode::snprintf(textIndTitle5dxBuffer, TEXTINDTITLE5DX_SIZE, "%s", Title5dx);	
	Unicode::snprintf(textIndTitle6dxBuffer, TEXTINDTITLE6DX_SIZE, "%s", Title6dx);	
	Unicode::snprintf(textIndTitle7dxBuffer, TEXTINDTITLE7DX_SIZE, "%s", Title7dx);	
	Unicode::snprintf(textIndTitle8dxBuffer, TEXTINDTITLE8DX_SIZE, "%s", Title8dx);	
	
//----- Colonna di sinistra

	if ( Indicators[debug_mode_scroll_sx - 7].TIPO == INT )
		Unicode::snprintf(textIndValue1sxBuffer, TEXTINDVALUE1SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 7].intValore);
	else
		Unicode::snprintfFloat(textIndValue1sxBuffer, TEXTINDVALUE1SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 7].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx - 6].TIPO == INT )
		Unicode::snprintf(textIndValue2sxBuffer, TEXTINDVALUE2SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 6].intValore);
	else
		Unicode::snprintfFloat(textIndValue2sxBuffer, TEXTINDVALUE2SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 6].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx - 5].TIPO == INT )
		Unicode::snprintf(textIndValue3sxBuffer, TEXTINDVALUE3SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 5].intValore);
	else
		Unicode::snprintfFloat(textIndValue3sxBuffer, TEXTINDVALUE3SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 5].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx - 4].TIPO == INT )
		Unicode::snprintf(textIndValue4sxBuffer, TEXTINDVALUE4SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 4].intValore);
	else
		Unicode::snprintfFloat(textIndValue4sxBuffer, TEXTINDVALUE4SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 4].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx - 3].TIPO == INT )
		Unicode::snprintf(textIndValue5sxBuffer, TEXTINDVALUE5SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 3].intValore);
	else
		Unicode::snprintfFloat(textIndValue5sxBuffer, TEXTINDVALUE5SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 3].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx - 2].TIPO == INT )
		Unicode::snprintf(textIndValue6sxBuffer, TEXTINDVALUE6SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 2].intValore);
	else
		Unicode::snprintfFloat(textIndValue6sxBuffer, TEXTINDVALUE6SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 2].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx - 1].TIPO == INT )
		Unicode::snprintf(textIndValue7sxBuffer, TEXTINDVALUE7SX_SIZE, "%d", Indicators[debug_mode_scroll_sx - 1].intValore);
	else
		Unicode::snprintfFloat(textIndValue7sxBuffer, TEXTINDVALUE7SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx - 1].floatValore);
	
	if ( Indicators[debug_mode_scroll_sx].TIPO == INT )
		Unicode::snprintf(textIndValue8sxBuffer, TEXTINDVALUE8SX_SIZE, "%d", Indicators[debug_mode_scroll_sx].intValore);
	else
		Unicode::snprintfFloat(textIndValue8sxBuffer, TEXTINDVALUE8SX_SIZE, "%.1f", Indicators[debug_mode_scroll_sx].floatValore);

//----- Colonna di destra
	
	if ( Indicators[debug_mode_scroll_dx - 7].TIPO == INT )
		Unicode::snprintf(textIndValue1dxBuffer, TEXTINDVALUE1DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 7].intValore);
	else
		Unicode::snprintfFloat(textIndValue1dxBuffer, TEXTINDVALUE1DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 7].floatValore);
	
	if ( Indicators[debug_mode_scroll_dx - 6].TIPO == INT )
		Unicode::snprintf(textIndValue2dxBuffer, TEXTINDVALUE2DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 6].intValore);
	else
		Unicode::snprintfFloat(textIndValue2dxBuffer, TEXTINDVALUE2DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 6].floatValore);
	
	if ( Indicators[debug_mode_scroll_dx - 5].TIPO == INT )
		Unicode::snprintf(textIndValue3dxBuffer, TEXTINDVALUE3DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 5].intValore);
	else
		Unicode::snprintfFloat(textIndValue3dxBuffer, TEXTINDVALUE3DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 5].floatValore);
	
	if ( Indicators[debug_mode_scroll_dx - 4].TIPO == INT )
		Unicode::snprintf(textIndValue4dxBuffer, TEXTINDVALUE4DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 4].intValore);
	else
		Unicode::snprintfFloat(textIndValue4dxBuffer, TEXTINDVALUE4DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 4].floatValore);
	
	if ( Indicators[debug_mode_scroll_dx - 3].TIPO == INT )
		Unicode::snprintf(textIndValue5dxBuffer, TEXTINDVALUE5DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 3].intValore);
	else
		Unicode::snprintfFloat(textIndValue5dxBuffer, TEXTINDVALUE5DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 3].floatValore);

	if ( Indicators[debug_mode_scroll_dx - 2].TIPO == INT )
		Unicode::snprintf(textIndValue6dxBuffer, TEXTINDVALUE6DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 2].intValore);
	else
		Unicode::snprintfFloat(textIndValue6dxBuffer, TEXTINDVALUE6DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 2].floatValore);

	if ( Indicators[debug_mode_scroll_dx - 1].TIPO == INT )
		Unicode::snprintf(textIndValue7dxBuffer, TEXTINDVALUE7DX_SIZE, "%d", Indicators[debug_mode_scroll_dx - 1].intValore);
	else
		Unicode::snprintfFloat(textIndValue7dxBuffer, TEXTINDVALUE7DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx - 1].floatValore);

	if ( Indicators[debug_mode_scroll_dx].TIPO == INT )
		Unicode::snprintf(textIndValue8dxBuffer, TEXTINDVALUE8DX_SIZE, "%d", Indicators[debug_mode_scroll_dx].intValore);
	else
		Unicode::snprintfFloat(textIndValue8dxBuffer, TEXTINDVALUE8DX_SIZE, "%.1f", Indicators[debug_mode_scroll_dx].floatValore);	
	
	
	textIndTitle1sx.invalidate();
	textIndTitle2sx.invalidate();
	textIndTitle3sx.invalidate();
	textIndTitle4sx.invalidate();
	textIndTitle5sx.invalidate();
	textIndTitle6sx.invalidate();
	textIndTitle7sx.invalidate();
	textIndTitle8sx.invalidate();
	
	textIndTitle1dx.invalidate();
	textIndTitle2dx.invalidate();
	textIndTitle3dx.invalidate();
	textIndTitle4dx.invalidate();
	textIndTitle5dx.invalidate();
	textIndTitle6dx.invalidate();
	textIndTitle7dx.invalidate();
	textIndTitle8dx.invalidate();


	textIndValue1sx.invalidate();
	textIndValue2sx.invalidate();
	textIndValue3sx.invalidate();
	textIndValue4sx.invalidate();
	textIndValue5sx.invalidate();
	textIndValue6sx.invalidate();
	textIndValue7sx.invalidate();
	textIndValue8sx.invalidate();
	
	textIndValue1dx.invalidate();
	textIndValue2dx.invalidate();
	textIndValue3dx.invalidate();
	textIndValue4dx.invalidate();
	textIndValue5dx.invalidate();
	textIndValue6dx.invalidate();
	textIndValue7dx.invalidate();
	textIndValue8dx.invalidate();
	
	
}

void DEBUG_MODEView::checkChangeScreen()
{
	switch ( Indicators[DRIVE_MODE].intValore ){
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
