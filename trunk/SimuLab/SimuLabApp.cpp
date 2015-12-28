/***************************************************************
 * Name:      SimuLabApp.cpp
 * Purpose:   Code for Application Class
 * Author:    WANG Mengchang (wangmengchang@gmail.com)
 * Created:   2009-07-10
 * Copyright: WANG Mengchang (http://hi.baidu.com/thym)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "SimuLabApp.h"
#include "SimuLabMain.h"

IMPLEMENT_APP(SimuLabApp);

bool SimuLabApp::OnInit()
{
    wxInitAllImageHandlers();

    SimuLabFrame* frame = new SimuLabFrame(0L);

    frame->Show();

    return true;
}
