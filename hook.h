#ifndef HOOK_H
#define HOOK_H
#include <windows.h>
#include <QObject>
class Hook:public QObject
{
    Q_OBJECT
public:
    Hook();
    enum Type{T,G,F,H}; //自定义枚举按键
    void installHook(); //安装钩子函数
    void unInstallHook(); //卸载钩子函数
    void sendSignal(Type type);
    Q_ENUM(Type) //注册枚举类型进元对象系统，否则无法将枚举类型作为信号参数传递
signals:
    void sendKeyType(Type); //发送按键监控信号
};

#endif // HOOK_H
