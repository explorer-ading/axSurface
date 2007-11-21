/*
 * Copyright (C) 2006, 2007 Apple Computer, Inc.  All rights reserved.
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
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BTGlyphPageTreeNode_h
#define BTGlyphPageTreeNode_h

#include "Shared.h"
#include <wtf/unicode/Unicode.h>
#include <wtf/Noncopyable.h>
#include <wtf/HashMap.h>

namespace WebCore {

#ifndef __OWB__
class FontData;
class GlyphPageTreeNode;
#endif

#ifdef __OWB__
}

using WebCore::Shared;

namespace BAL {

class BTFontData;
class GlyphPageTreeNode;

#endif //__OWB__
typedef unsigned short Glyph;

// Holds the glyph index and the corresponding FontData information for a given
// character.
struct GlyphData {
    Glyph glyph;
    const BTFontData* fontData;
};

// A GlyphPage contains a fixed-size set of GlyphData mappings for a contiguous
// range of characters in the Unicode code space. GlyphPages are indexed
// starting from 0 and incrementing for each 256 glyphs.
//
// One page may actually include glyphs from other fonts if the characters are
// missing in the parimary font. It is owned by exactly one GlyphPageTreeNode,
// although multiple nodes may reference it as their "page" if they are supposed
// to be overriding the parent's node, but provide no additional information.

struct BTGlyphPage : public Shared<BTGlyphPage> {
    BTGlyphPage()
        : m_owner(0)
    {
    }

    BTGlyphPage(GlyphPageTreeNode* owner)
        : m_owner(owner)
    {
    }

    static const size_t size = 256; // Covers Latin-1 in a single page.
    GlyphData m_glyphs[size];
    GlyphPageTreeNode* m_owner;

    const GlyphData& glyphDataForCharacter(UChar32 c) const { return m_glyphs[c % size]; }
    void setGlyphDataForCharacter(UChar32 c, Glyph g, const BTFontData* f)
    {
        setGlyphDataForIndex(c % size, g, f);
    }
    void setGlyphDataForIndex(unsigned index, Glyph g, const BTFontData* f)
    {
        m_glyphs[index].glyph = g;
        m_glyphs[index].fontData = f;
    }
    GlyphPageTreeNode* owner() const { return m_owner; }
    // Implemented by the platform.
    bool fill(UChar* characterBuffer, unsigned bufferLength, const BTFontData* fontData);
};

// The glyph page tree is a data structure that maps (FontData, glyph page number)
// to a GlyphPage.  Level 0 (the "root") is special. There is one root
// GlyphPageTreeNode for each glyph page number.  The roots do not have a
// GlyphPage associated with them, and their initializePage() function is never
// called to fill the glyphs.
//
// Each root node maps a FontData pointer to another GlyphPageTreeNode at
// level 1 (the "root child") that stores the actual glyphs for a specific font data.
// These nodes will only have a GlyphPage if they have glyphs for that range.
//
// Levels greater than one correspond to subsequent levels of the fallback list
// for that font. These levels override their parent's page of glyphs by
// filling in holes with the new font (thus making a more complete page).
//
// A NULL FontData pointer corresponds to the system fallback
// font. It is tracked separately from the regular pages and overrides so that
// the glyph pages do not get polluted with these last-resort glyphs. The
// system fallback page is not populated at construction like the other pages,
// but on demand for each glyph, because the system may need to use different
// fallback fonts for each. This lazy population is done by the Font.
class GlyphPageTreeNode {
public:
    GlyphPageTreeNode()
        : m_parent(0)
        , m_level(0)
        , m_isSystemFallback(false)
        , m_systemFallbackChild(0)
        , m_customFontCount(0)
#ifndef NDEBUG
        , m_pageNumber(0)
#endif
    {
    }

    ~GlyphPageTreeNode();

    static HashMap<int, GlyphPageTreeNode*>* roots;
    static GlyphPageTreeNode* pageZeroRoot;

    static GlyphPageTreeNode* getRootChild(const BTFontData* fontData, unsigned pageNumber)
    {
        return getRoot(pageNumber)->getChild(fontData, pageNumber);
    }

    static void pruneTreeCustomFontData(const BTFontData*);

    void pruneCustomFontData(const BTFontData*);

    GlyphPageTreeNode* parent() const { return m_parent; }
    GlyphPageTreeNode* getChild(const BTFontData*, unsigned pageNumber);

    // Returns a page of glyphs (or NULL if there are no glyphs in this page's character range).
    BTGlyphPage* page() const { return m_page.get(); }

    // Returns the level of this node. See class-level comment.
    unsigned level() const { return m_level; }

    // The system fallback font has special rules (see above).
    bool isSystemFallback() const { return m_isSystemFallback; }

private:
    static GlyphPageTreeNode* getRoot(unsigned pageNumber);
    void initializePage(const BTFontData*, unsigned pageNumber);

    GlyphPageTreeNode* m_parent;
    RefPtr<BTGlyphPage> m_page;
    unsigned m_level;
    bool m_isSystemFallback;
    HashMap<const BTFontData*, GlyphPageTreeNode*> m_children;
    GlyphPageTreeNode* m_systemFallbackChild;
    unsigned m_customFontCount;

#ifndef NDEBUG
    unsigned m_pageNumber;
#endif
};

} // namespace WebCore

#endif // BTGlyphPageTreeNode_h
