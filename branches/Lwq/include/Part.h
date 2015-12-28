#ifndef PART_H
#define PART_H


class Part
{
    public:
        Part();
        virtual ~Part();
        int getType();
        void setType(int tp);
        void setGPriority(int gp);
        void setLPriority(int lp);
        int getGPriority();
        int getLPriority();
        int getProcessNum();
        void setProcessNum(int pr);
        int getID();
    protected:
        int WIP_Type;//在制品类型
        int global_priority;//全局优先级，数字越小，优先级越高
        int local_priority;//局部优先级，数字越小，优先级越高
        int process_num;//绑定的工艺路线序号
        int ID;//id
        static int Part_ID;

        double enter_time;//the time that this part enter the simulation
        double leave_time;//the time that this part has been finished.
    private:
};

#endif // PART_H
