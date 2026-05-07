#pragma once
#include <base/resource.h>

namespace rhi
{
    class CommandList : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::CommandList;
        }

        virtual void begin() = 0;
        virtual void end() = 0;

        virtual void beginRendering(const RenderingInfo& info) = 0;
        virtual void endRendering() = 0;

        virtual void bindPipeline(PipelineState* pso) = 0;
        virtual void bindBindingSet(uint32_t setIndex, BindingSet* set) = 0;
        virtual void bindVertexBuffer(uint32_t slot, Buffer* buf, uint64_t offset) = 0;
        virtual void bindIndexBuffer(Buffer* buf, uint64_t offset, bool is32bit) = 0;

        virtual void setViewport(const Viewport& vp) = 0;
        virtual void setScissor(const Rect& sc) = 0;

        virtual void draw(uint32_t vertexCount, uint32_t instanceCount = 1,
            uint32_t firstVertex = 0, uint32_t firstInstance = 0) = 0;
        virtual void drawIndexed(uint32_t indexCount, uint32_t instanceCount = 1,
            uint32_t firstIndex = 0, int32_t vertexOffset = 0,
            uint32_t firstInstance = 0) = 0;
        virtual void drawIndirect(Buffer* buffer, uint64_t offset,
            uint32_t drawCount, uint32_t stride) = 0;
        virtual void drawIndexedIndirect(Buffer* buffer, uint64_t offset,
            uint32_t drawCount, uint32_t stride) = 0;

        virtual void dispatch(uint32_t groupX, uint32_t groupY, uint32_t groupZ) = 0;
        virtual void dispatchIndirect(Buffer* buffer, uint64_t offset) = 0;

        virtual void copyBuffer(Buffer* src, Buffer* dst, uint64_t size,
            uint64_t srcOffset = 0, uint64_t dstOffset = 0) = 0;
        virtual void copyTexture() = 0;
        virtual void clearColor(const RenderingAttachmentInfo& attachment) = 0;
        virtual void clearDepthStencil(const RenderingAttachmentInfo& attachment) = 0;

        virtual void resourceBarrier(const TextureBarrier& barrier) = 0;
        virtual void resourceBarrier(const BufferBarrier& barrier) = 0;

        virtual void buildAccelerationStructure() {}
        virtual void traceRays() {}
    };
}