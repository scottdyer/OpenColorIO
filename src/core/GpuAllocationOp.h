/*
Copyright (c) 2003-2010 Sony Pictures Imageworks Inc., et al.
All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
* Neither the name of Sony Pictures Imageworks nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef INCLUDED_OCIO_GPUALLOCATIONOP_H
#define INCLUDED_OCIO_GPUALLOCATIONOP_H

#include <OpenColorIO/OpenColorIO.h>

#include "Op.h"
#include "Processor.h"

OCIO_NAMESPACE_ENTER
{
    class GpuAllocationOp;
    typedef SharedPtr<GpuAllocationOp> GpuAllocationOpRcPtr;
    
    class GpuAllocationOp : public Op
    {
    public:
        GpuAllocationOp(GpuAllocation allocation,
                        float min,
                        float max);
        virtual ~GpuAllocationOp();
        
        virtual std::string getInfo() const;
        virtual std::string getCacheID() const;
        
        virtual void setup();
        virtual void apply(float* rgbaBuffer, long numPixels) const;
        virtual bool supportsGpuShader() const;
        
        GpuAllocation getAllocation() const;
        float getMin() const;
        float getMax() const;
    
    private:
        GpuAllocation m_allocation;
        float m_min;
        float m_max;
        
        std::string m_cacheID;
    };
    
    void CreateGpuAllocationOp(LocalProcessor & processor,
                               GpuAllocation allocation,
                               float min, float max);
}
OCIO_NAMESPACE_EXIT

#endif
