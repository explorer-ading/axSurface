if(ENABLE_SVG)
    list(APPEND WEBCORE_SRC
        svg/ColorDistance.cpp
        svg/SVGAElement.cpp
        svg/SVGAltGlyphElement.cpp
        svg/SVGAngle.cpp
        svg/SVGAnimateColorElement.cpp
        svg/SVGAnimateElement.cpp
        svg/SVGAnimateMotionElement.cpp
        svg/SVGAnimateTransformElement.cpp
        svg/SVGAnimatedPathData.cpp
        svg/SVGAnimatedPoints.cpp
        svg/SVGAnimationElement.cpp
        svg/SVGCircleElement.cpp
        svg/SVGClipPathElement.cpp
        svg/SVGColor.cpp
        svg/SVGComponentTransferFunctionElement.cpp
        svg/SVGCursorElement.cpp
        svg/SVGDefsElement.cpp
        svg/SVGDescElement.cpp
        svg/SVGDocument.cpp
        svg/SVGDocumentExtensions.cpp
        svg/SVGElement.cpp
        svg/SVGElementInstance.cpp
        svg/SVGElementInstanceList.cpp
        svg/SVGEllipseElement.cpp
        svg/SVGExternalResourcesRequired.cpp
        svg/SVGFEBlendElement.cpp
        svg/SVGFEColorMatrixElement.cpp
        svg/SVGFEComponentTransferElement.cpp
        svg/SVGFECompositeElement.cpp
        svg/SVGFEDiffuseLightingElement.cpp
        svg/SVGFEDisplacementMapElement.cpp
        svg/SVGFEDistantLightElement.cpp
        svg/SVGFEFloodElement.cpp
        svg/SVGFEFuncAElement.cpp
        svg/SVGFEFuncBElement.cpp
        svg/SVGFEFuncGElement.cpp
        svg/SVGFEFuncRElement.cpp
        svg/SVGFEGaussianBlurElement.cpp
        svg/SVGFEImageElement.cpp
        svg/SVGFELightElement.cpp
        svg/SVGFEMergeElement.cpp
        svg/SVGFEMergeNodeElement.cpp
        svg/SVGFEMorphologyElement.cpp
        svg/SVGFEOffsetElement.cpp
        svg/SVGFEPointLightElement.cpp
        svg/SVGFESpecularLightingElement.cpp
        svg/SVGFESpotLightElement.cpp
        svg/SVGFETileElement.cpp
        svg/SVGFETurbulenceElement.cpp
        svg/SVGFilterElement.cpp
        svg/SVGFilterPrimitiveStandardAttributes.cpp
        svg/SVGFitToViewBox.cpp
        svg/SVGFont.cpp
        svg/SVGFontData.cpp
        svg/SVGFontElement.cpp
        svg/SVGFontFaceElement.cpp
        svg/SVGFontFaceFormatElement.cpp
        svg/SVGFontFaceNameElement.cpp
        svg/SVGFontFaceSrcElement.cpp
        svg/SVGFontFaceUriElement.cpp
        svg/SVGForeignObjectElement.cpp
        svg/SVGGElement.cpp
        svg/SVGGlyphElement.cpp
        svg/SVGGradientElement.cpp
        svg/SVGHKernElement.cpp
        svg/SVGImageElement.cpp
        svg/SVGImageLoader.cpp
        svg/SVGVKernElement.cpp
        svg/SVGLangSpace.cpp
        svg/SVGLength.cpp
        svg/SVGLengthList.cpp
        svg/SVGLineElement.cpp
        svg/SVGLinearGradientElement.cpp
        svg/SVGLocatable.cpp
        svg/SVGMPathElement.cpp
        svg/SVGMarkerElement.cpp
        svg/SVGMaskElement.cpp
        svg/SVGMetadataElement.cpp
        svg/SVGMissingGlyphElement.cpp
        svg/SVGNumberList.cpp
        svg/SVGPaint.cpp
        svg/SVGParserUtilities.cpp
        svg/SVGPathElement.cpp
        svg/SVGPathSegArc.cpp
        svg/SVGPathSegClosePath.cpp
        svg/SVGPathSegCurvetoCubic.cpp
        svg/SVGPathSegCurvetoCubicSmooth.cpp
        svg/SVGPathSegCurvetoQuadratic.cpp
        svg/SVGPathSegCurvetoQuadraticSmooth.cpp
        svg/SVGPathSegLineto.cpp
        svg/SVGPathSegLinetoHorizontal.cpp
        svg/SVGPathSegLinetoVertical.cpp
        svg/SVGPathSegList.cpp
        svg/SVGPathSegMoveto.cpp
        svg/SVGPatternElement.cpp
        svg/SVGPointList.cpp
        svg/SVGPolyElement.cpp
        svg/SVGPolygonElement.cpp
        svg/SVGPolylineElement.cpp
        svg/SVGPreserveAspectRatio.cpp
        svg/SVGRadialGradientElement.cpp
        svg/SVGRectElement.cpp
        svg/SVGSVGElement.cpp
        svg/SVGScriptElement.cpp
        svg/SVGSetElement.cpp
        svg/SVGStopElement.cpp
        svg/SVGStringList.cpp
        svg/SVGStylable.cpp
        svg/SVGStyleElement.cpp
        svg/SVGStyledElement.cpp
        svg/SVGStyledLocatableElement.cpp
        svg/SVGStyledTransformableElement.cpp
        svg/SVGSwitchElement.cpp
        svg/SVGSymbolElement.cpp
        svg/SVGTRefElement.cpp
        svg/SVGTSpanElement.cpp
        svg/SVGTests.cpp
        svg/SVGTextContentElement.cpp
        svg/SVGTextElement.cpp
        svg/SVGTextPathElement.cpp
        svg/SVGTextPositioningElement.cpp
        svg/SVGTitleElement.cpp
        svg/SVGTransform.cpp
        svg/SVGTransformDistance.cpp
        svg/SVGTransformList.cpp
        svg/SVGTransformable.cpp
        svg/SVGURIReference.cpp
        svg/SVGUseElement.cpp
        svg/SVGViewElement.cpp
        svg/SVGViewSpec.cpp
        svg/SVGZoomAndPan.cpp
        svg/SVGZoomEvent.cpp
        svg/animation/SMILTime.cpp
        svg/animation/SMILTimeContainer.cpp
        svg/animation/SVGSMILElement.cpp
        svg/graphics/SVGImage.cpp
        svg/graphics/filters/SVGFilter.cpp
        svg/graphics/filters/SVGFilterBuilder.cpp
        svg/graphics/filters/SVGFEConvolveMatrix.cpp
        svg/graphics/filters/SVGFEDiffuseLighting.cpp
        svg/graphics/filters/SVGFEDisplacementMap.cpp
        svg/graphics/filters/SVGFEFlood.cpp
        svg/graphics/filters/SVGFEImage.cpp
        svg/graphics/filters/SVGFELighting.cpp
        svg/graphics/filters/SVGFEMerge.cpp
        svg/graphics/filters/SVGFEMorphology.cpp
        svg/graphics/filters/SVGFEOffset.cpp
        svg/graphics/filters/SVGFESpecularLighting.cpp
        svg/graphics/filters/SVGFETile.cpp
        svg/graphics/filters/SVGFETurbulence.cpp
        svg/graphics/filters/SVGLightSource.cpp
    )
    list(APPEND IDL_SRC
        svg/ElementTimeControl.idl
        svg/SVGAElement.idl
        svg/SVGAltGlyphElement.idl
        svg/SVGAngle.idl
        svg/SVGAnimateColorElement.idl
        svg/SVGAnimateElement.idl
        svg/SVGAnimateTransformElement.idl
        svg/SVGAnimatedAngle.idl
        svg/SVGAnimatedBoolean.idl
        svg/SVGAnimatedEnumeration.idl
        svg/SVGAnimatedInteger.idl
        svg/SVGAnimatedLength.idl
        svg/SVGAnimatedLengthList.idl
        svg/SVGAnimatedNumber.idl
        svg/SVGAnimatedNumberList.idl
        svg/SVGAnimatedPathData.idl
        svg/SVGAnimatedPoints.idl
        svg/SVGAnimatedPreserveAspectRatio.idl
        svg/SVGAnimatedRect.idl
        svg/SVGAnimatedString.idl
        svg/SVGAnimatedTransformList.idl
        svg/SVGAnimationElement.idl
        svg/SVGCircleElement.idl
        svg/SVGClipPathElement.idl
        svg/SVGColor.idl
        svg/SVGComponentTransferFunctionElement.idl
        svg/SVGCursorElement.idl
        svg/SVGDefsElement.idl
        svg/SVGDescElement.idl
        svg/SVGDocument.idl
        svg/SVGElement.idl
        svg/SVGElementInstance.idl
        svg/SVGElementInstanceList.idl
        svg/SVGEllipseElement.idl
        svg/SVGException.idl
        svg/SVGExternalResourcesRequired.idl
        svg/SVGFEBlendElement.idl
        svg/SVGFEColorMatrixElement.idl
        svg/SVGFEComponentTransferElement.idl
        svg/SVGFECompositeElement.idl
        svg/SVGFEDiffuseLightingElement.idl
        svg/SVGFEDisplacementMapElement.idl
        svg/SVGFEDistantLightElement.idl
        svg/SVGFEFloodElement.idl
        svg/SVGFEFuncAElement.idl
        svg/SVGFEFuncBElement.idl
        svg/SVGFEFuncGElement.idl
        svg/SVGFEFuncRElement.idl
        svg/SVGFEGaussianBlurElement.idl
        svg/SVGFEImageElement.idl
        svg/SVGFEMergeElement.idl
        svg/SVGFEMergeNodeElement.idl
        svg/SVGFEOffsetElement.idl
        svg/SVGFEPointLightElement.idl
        svg/SVGFESpecularLightingElement.idl
        svg/SVGFESpotLightElement.idl
        svg/SVGFETileElement.idl
        svg/SVGFETurbulenceElement.idl
        svg/SVGFilterElement.idl
        svg/SVGFilterPrimitiveStandardAttributes.idl
        svg/SVGFitToViewBox.idl
        svg/SVGFontElement.idl
        svg/SVGFontFaceElement.idl
        svg/SVGFontFaceFormatElement.idl
        svg/SVGFontFaceNameElement.idl
        svg/SVGFontFaceSrcElement.idl
        svg/SVGFontFaceUriElement.idl
        svg/SVGForeignObjectElement.idl
        svg/SVGGElement.idl
        svg/SVGGlyphElement.idl
        svg/SVGGradientElement.idl
        svg/SVGHKernElement.idl
        svg/SVGImageElement.idl
        svg/SVGVKernElement.idl
        svg/SVGLangSpace.idl
        svg/SVGLength.idl
        svg/SVGLengthList.idl
        svg/SVGLineElement.idl
        svg/SVGLinearGradientElement.idl
        svg/SVGLocatable.idl
        svg/SVGMarkerElement.idl
        svg/SVGMaskElement.idl
        svg/SVGMatrix.idl
        svg/SVGMetadataElement.idl
        svg/SVGMissingGlyphElement.idl
        svg/SVGFEMorphologyElement.idl
        svg/SVGNumber.idl
        svg/SVGNumberList.idl
        svg/SVGPaint.idl
        svg/SVGPathElement.idl
        svg/SVGPathSeg.idl
        svg/SVGPathSegArcAbs.idl
        svg/SVGPathSegArcRel.idl
        svg/SVGPathSegClosePath.idl
        svg/SVGPathSegCurvetoCubicAbs.idl
        svg/SVGPathSegCurvetoCubicRel.idl
        svg/SVGPathSegCurvetoCubicSmoothAbs.idl
        svg/SVGPathSegCurvetoCubicSmoothRel.idl
        svg/SVGPathSegCurvetoQuadraticAbs.idl
        svg/SVGPathSegCurvetoQuadraticRel.idl
        svg/SVGPathSegCurvetoQuadraticSmoothAbs.idl
        svg/SVGPathSegCurvetoQuadraticSmoothRel.idl
        svg/SVGPathSegLinetoAbs.idl
        svg/SVGPathSegLinetoHorizontalAbs.idl
        svg/SVGPathSegLinetoHorizontalRel.idl
        svg/SVGPathSegLinetoRel.idl
        svg/SVGPathSegLinetoVerticalAbs.idl
        svg/SVGPathSegLinetoVerticalRel.idl
        svg/SVGPathSegList.idl
        svg/SVGPathSegMovetoAbs.idl
        svg/SVGPathSegMovetoRel.idl
        svg/SVGPatternElement.idl
        svg/SVGPoint.idl
        svg/SVGPointList.idl
        svg/SVGPolygonElement.idl
        svg/SVGPolylineElement.idl
        svg/SVGPreserveAspectRatio.idl
        svg/SVGRadialGradientElement.idl
        svg/SVGRect.idl
        svg/SVGRectElement.idl
        svg/SVGRenderingIntent.idl
        svg/SVGSVGElement.idl
        svg/SVGScriptElement.idl
        svg/SVGSetElement.idl
        svg/SVGStopElement.idl
        svg/SVGStringList.idl
        svg/SVGStylable.idl
        svg/SVGStyleElement.idl
        svg/SVGSwitchElement.idl
        svg/SVGSymbolElement.idl
        svg/SVGTRefElement.idl
        svg/SVGTSpanElement.idl
        svg/SVGTests.idl
        svg/SVGTextContentElement.idl
        svg/SVGTextElement.idl
        svg/SVGTextPathElement.idl
        svg/SVGTextPositioningElement.idl
        svg/SVGTitleElement.idl
        svg/SVGTransform.idl
        svg/SVGTransformList.idl
        svg/SVGTransformable.idl
        svg/SVGURIReference.idl
        svg/SVGUnitTypes.idl
        svg/SVGUseElement.idl
        svg/SVGViewElement.idl
        svg/SVGViewSpec.idl
        svg/SVGZoomAndPan.idl
        svg/SVGZoomEvent.idl
    )
endif(ENABLE_SVG)
