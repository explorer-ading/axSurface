/*
 * This file is part of the WebKit project.
 *
 * Copyright (C) 2007 Eric Seidel <eric@webkit.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef RenderSVGHiddenContainer_h
#define RenderSVGHiddenContainer_h

#ifdef SVG_SUPPORT

#include "RenderContainer.h"

namespace WebCore {
    
    class SVGStyledElement;
    
    // This class is for containers which are never drawn, but do need to support style
    // <defs>, <linearGradient>, <radialGradient> are all good examples
    class RenderSVGHiddenContainer : public RenderContainer {
    public:
        RenderSVGHiddenContainer(SVGStyledElement*);
        virtual ~RenderSVGHiddenContainer();
        
        virtual bool isSVGContainer() const { return true; }
        virtual const char* renderName() const { return "RenderSVGHiddenContainer"; }
        
        virtual bool requiresLayer();
        
        virtual short lineHeight(bool b, bool isRootLineBox = false) const;
        virtual short baselinePosition(bool b, bool isRootLineBox = false) const;
        
        virtual void calcMinMaxWidth();
        virtual void layout();
        virtual void paint(PaintInfo&, int parentX, int parentY);
        
        virtual IntRect getAbsoluteRepaintRect();
        virtual void absoluteRects(Vector<IntRect>& rects, int tx, int ty);
        
        virtual AffineTransform absoluteTransform() const;
        virtual AffineTransform localTransform() const;
        
        virtual bool nodeAtPoint(const HitTestRequest&, HitTestResult&, int x, int y, int tx, int ty, HitTestAction);
        
    };
}


#endif // SVG_SUPPORT
#endif // RenderSVGHiddenContainer_h