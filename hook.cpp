#include "hook.h"
#include <QDebug>
#pragma comment  (lib, "User32.lib")

static HHOOK keyHook=nullptr;//钩子对象
static Hook* hook;//Qt界面中调用Hook类的对象
LRESULT CALLBACK keyProc(int nCode,WPARAM wParam,LPARAM lParam){//钩子消息函数，系统消息队列信息会返回到该函数中
    KBDLLHOOKSTRUCT* pkbhs = (KBDLLHOOKSTRUCT*)lParam;//lParam用于判断按键类型
    if(wParam == WM_KEYDOWN){//wParam用于判断事件类型，当前为按键按下事件
        if(pkbhs->vkCode == 0x54){ //按下t
            hook->sendSignal(Hook::T);//安装钩子的对象发出按键监听信号
        }
        if(pkbhs->vkCode == 0x47){ //按下g
            hook->sendSignal(Hook::G);
        }
        if(pkbhs->vkCode == 0x46){ //按下f
            hook->sendSignal(Hook::F);
        }
        if(pkbhs->vkCode == 0x48){ //按下h
            hook->sendSignal(Hook::H);
        }
    }
    return CallNextHookEx(keyHook,nCode,wParam,lParam);//继续原有的事件队列
}

Hook::Hook()
{

}

void Hook::installHook(){//安装钩子函数
    keyHook = SetWindowsHookEx(WH_KEYBOARD_LL,keyProc,nullptr,0);
    hook = this;
}
void Hook::unInstallHook(){//删除钩子函数
    UnhookWindowsHookEx(keyHook);
    keyHook = nullptr;
}

void Hook::sendSignal(Type type){//发送信号函数
    emit sendKeyType(type);
}
