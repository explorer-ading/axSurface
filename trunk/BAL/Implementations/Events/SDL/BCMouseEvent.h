/*
 * Copyright (C) 2007 Pleyo.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Pleyo nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY PLEYO AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PLEYO OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file  BCMouseEvent.h
 *
 * @brief Concretisation of mouse event
 *
 * Repository informations :
 * - $URL$
 * - $Rev$
 * - $Date: 2006/05/11 13:44:56 $
 *
 * This header file is private. Only IDL interface is public.
 *
 */

#include "BIMouseEvent.h"
#include "../Common/BCCommonInputEventData.h"

namespace BC
{

/**
 * @brief the MouseEvent
 *
 * The mouse event
 *
 * @see BIEvent, BIEventLoop
 */
class BCMouseEvent : public BAL::BIMouseEvent, public BCCommonInputEventData {
public:
  BCMouseEvent(MouseEventType, const IntPoint& pos, const IntPoint& globalPos, MouseButton,
                int clickCount, bool shift, bool ctrl, bool alt, bool meta);

  virtual const IntPoint& pos() const;
  virtual const IntPoint& globalPos() const;

  virtual MouseButton button() const;
  virtual MouseEventType eventType() const { return m_eventType; }
  virtual int clickCount() const;
  virtual double timestamp() const { return m_timestamp; }
  virtual BIEvent* clone() const;

  virtual bool shiftKey() const { return BCCommonInputEventData::shiftKey(); }
  virtual bool ctrlKey() const { return BCCommonInputEventData::ctrlKey(); }
  virtual bool altKey() const { return BCCommonInputEventData::altKey(); }
  virtual bool metaKey() const { return BCCommonInputEventData::metaKey(); }

private:
  IntPoint m_position;
  IntPoint m_globalPosition;
  MouseButton m_button;
  MouseEventType m_eventType;
  int m_clickCount;
  double m_timestamp; // unit: seconds
};

}