#ifndef __lwqstage__
#define __lwqstage__

#include "include/MyBase.h"
#include "include/Machine.h"
#include "include/Part.h"
/*
 * 等待
 * 零件进入
 * 如果工人闲
 * 工人操作
 * 长度增长
 * 如果（时间满足 或 长度满足）推入下一工位
*/



class lwqStage : public MyBase
{

public:
	lwqStage();
	~lwqStage();

	bool TryPush();
	bool Operate();
protected:
	double StageLength;
		//
	Part *beOperated;
	Part *entered;
	lwqstage* NextStage;
	
};
#endif // __lwqstage__
