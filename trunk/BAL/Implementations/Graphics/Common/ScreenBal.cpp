/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
 * Copyright (C) 2006 Michael Emmel mike.emmel@gmail.com
 * Copyright (C) 2007 Pleyo.  All rights reserved.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "Screen.h"

#include "BIWindow.h"
#include "IntRect.h"
#include "FloatRect.h"
#include "Widget.h"

namespace BAL
{

// FIXME SRO BAL should be independant of Page !!
FloatRect screenRect(Widget* widget)
{
//    return FloatRect(0, 0, 800, 600);
    // XXX SRO old BIWindow based code was :
    FloatRect rect;
    BIWindow* window = widget->drawable();
    if (!window) {
        return rect;
    }
    rect.setWidth(window->width());
    rect.setHeight(window->height());
    return rect;
}

FloatRect screenAvailableRect(Widget* widget)
{
//    return FloatRect(0 ,0, 800, 600);
    return screenRect(widget);
}

int screenDepth(Widget* widget)
{
//    return 32;
    // XXX SRO old BIWindow based code was :
    BIWindow* window = widget->drawable();
    if (!window)
        return 32;
    return window->depth();
}

int screenDepthPerComponent(Widget*)
{
    return 32;
}
bool screenIsMonochrome(Widget*)
{
    return false;
}

FloatRect usableScreenRect(Widget* w)
{
    return screenRect(w);
}

}
