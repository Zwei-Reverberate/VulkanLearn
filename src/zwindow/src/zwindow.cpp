#include <string>
#include <qwindow.h>
#include <zwindow.h>

namespace zwin
{
    class ZWindowImpl : public QWindow, public ZWindow
    {
    public:
        ZWindowImpl(const WindowConfig& config)
        {
            setTitle(QString::fromStdString(config.title));
            resize(config.width, config.height);
            if (config.isFull) 
            {
                setVisibility(QWindow::FullScreen);
            }
        }

        void* getNativeHandle() const override 
        {
            return (void*)winId();
        }

        void show() override 
        { 
            QWindow::show(); 
        }

        void setWindowTitle(const std::string& title) override 
        { 
            setTitle(QString::fromStdString(title)); 
        }

        void onResize(ResizeCallback cb) override 
        {
            m_resizeCb = cb; 
        }

        void onDraw(RenderCallback cb) override 
        {
            m_renderCb = cb; 
        }

    protected:
        void resizeEvent(QResizeEvent* event) override
        {
            if (m_resizeCb)
            {
               // m_resizeCb(event->size().width(), ev->size().height());
            }
        }

        
    private:
        ResizeCallback m_resizeCb;
        RenderCallback m_renderCb;
    };

    std::unique_ptr<ZWindow> ZWindow::Create(const WindowConfig& config) 
    {
        return std::make_unique<ZWindowImpl>(config);
    }
}