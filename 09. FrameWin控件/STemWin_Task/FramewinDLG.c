/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
/* 控件ID */
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_0   (GUI_ID_USER + 0x01)

/* 资源表 */
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 480, 854,FRAMEWIN_CF_MOVEABLE, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button0", ID_BUTTON_0, 10, 30, 160, 48, 0, 0x0, 0 },
};

/**
  * @brief 对话框回调函数
  * @note 无
  * @param pMsg：消息指针
  * @retval 无
  */
static void _cbDialog(WM_MESSAGE * pMsg)
{
  WM_HWIN hItem;
  int     NCode;
  int     Id;

  switch (pMsg->MsgId)
  {
    case WM_INIT_DIALOG:
      /* 初始化框架窗口控件 */
      hItem = pMsg->hWin;
      FRAMEWIN_SetTitleHeight(hItem, 32);
      FRAMEWIN_SetFont(hItem, GUI_FONT_32_1);
      FRAMEWIN_SetText(hItem, "STemWIN@EmbedFire STM32H743");
      /* 初始化Button0 */
      hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
      BUTTON_SetFont(hItem, GUI_FONT_24B_ASCII);
      break;
    case WM_NOTIFY_PARENT:
      /* 获取控件ID */
      Id = WM_GetId(pMsg->hWinSrc);
      /* 获取消息内容 */
      NCode = pMsg->Data.v;
      switch(Id)
      {
        case ID_BUTTON_0: // Notifications sent by 'Button'
        switch(NCode)
        {
          case WM_NOTIFICATION_CLICKED:
            break;
          case WM_NOTIFICATION_RELEASED:
            break;
        }
        break;
      }
      break;
    default:
      WM_DefaultProc(pMsg);
      break;
  }

}

/**
  * @brief 以对话框方式间接创建控件
  * @note 无
  * @param 无
  * @retval hWin：资源表中第一个控件的句柄
  */
WM_HWIN CreateFramewin(void)
{
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

/**
  * @brief GUI主任务
  * @note 无
  * @param 无
  * @retval 无
  */
void MainTask(void)
{
  /* 设置桌面窗口颜色 */
  WM_SetDesktopColor(GUI_BLUE);
  
	/* 创建对话框 */
	CreateFramewin();
  /* 开启光标 */
  GUI_CURSOR_Show();
  
	while (1)
	{
		GUI_Delay(500);
	}
}

/*************************** End of file ****************************/
