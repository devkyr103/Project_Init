#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace kyr
{
    class CTitleObject :
        public CGameObject
    {
    public:
        CTitleObject();
        ~CTitleObject();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(Gdiplus::Graphics* gp) override;
        virtual void Release() override;

    private:
        CImage* mImage;
    };

}

