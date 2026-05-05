#pragma once
#include <string>
#include <functional>
#include <memory>

namespace zwin
{
    struct WindowConfig
    {
        std::string title = "Zwei";
        int width = 1280;
        int height = 720;
        bool isFull = false;
    };

    class ZWindow
    {
    public:
        virtual ~ZWindow() = default;
        virtual void* getNativeHandle() const = 0;

        virtual void show() = 0;
        virtual void setWindowTitle(const std::string& title) = 0;


        using ResizeCallback = std::function<void(int w, int h)>;
        using RenderCallback = std::function<void()>;

        virtual void onResize(ResizeCallback cb) = 0;
        virtual void onDraw(RenderCallback cb) = 0;

        static std::unique_ptr<ZWindow> Create(const WindowConfig& config);
    };
}