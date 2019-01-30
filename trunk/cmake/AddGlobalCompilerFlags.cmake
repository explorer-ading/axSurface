if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_C_FLAGS "-std=c99 -Wall -W -Wcast-align -Wchar-subscripts -Wreturn-type -Wformat -Wformat-security -Wno-format-y2k -Wundef -Wmissing-format-attribute -Wpointer-arith -Wwrite-strings -Wno-unused-parameter -Wno-parentheses -w -fPIC")
	set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -W -Wcast-align -Wchar-subscripts -Wreturn-type -Wformat -Wformat-security -Wno-format-y2k -Wundef -Wmissing-format-attribute -Wpointer-arith -Wwrite-strings -Wno-unused-parameter -Wno-parentheses -w -fvisibility-inlines-hidden -fPIC")
    if(ENABLE_DEBUG)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O1")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O1")
    else(ENABLE_DEBUG)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
    endif(ENABLE_DEBUG)
else(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "Flag for Windows compiler is not implemented")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_definitions(-DWTF_CHANGES)

if(USE_I18N_QT)
    add_definitions(-DWTF_USE_QT4_UNICODE=1)
else(USE_I18N_QT)
    add_definitions(-DWTF_USE_ICU_UNICODE=1)
endif(USE_I18N_QT)

if(USE_NETWORK_CURL)
    add_definitions(-DWTF_USE_CURL=1)

    if(USE_NETWORK_CURL_OPENSSL)
        add_definitions(-DWTF_USE_CURL_OPENSSL=1)
    endif(USE_NETWORK_CURL_OPENSSL)

endif(USE_NETWORK_CURL)

if(USE_NETWORK_SOUP)
    add_definitions(-DWTF_USE_SOUP=1)
endif(USE_NETWORK_SOUP)

if(ENABLE_3D_RENDERING)
    add_definitions(-DENABLE_3D_RENDERING)
endif(ENABLE_3D_RENDERING)

if(ENABLE_ACCESSIBILITY)
    add_definitions(-DHAVE_ACCESSIBILITY)
endif(ENABLE_ACCESSIBILITY)

if(NOT ENABLE_DEBUG)
    add_definitions(-DNDEBUG)
endif(NOT ENABLE_DEBUG)
if(NOT ENABLE_FAST_MALLOC)
    add_definitions(-DUSE_SYSTEM_MALLOC)
endif(NOT ENABLE_FAST_MALLOC)

if(ENABLE_JIT_JSC)
    add_definitions(-DENABLE_JIT=1)
    if (ENABLE_YARR)
        add_definitions(-DENABLE_YARR_JIT=1)
    endif (ENABLE_YARR)
endif(ENABLE_JIT_JSC)

if(ENABLE_YARR)
    add_definitions(-DENABLE_YARR=1)
endif(ENABLE_YARR)

if(ENABLE_OWB_TRACES)
    add_definitions(-DENABLE_OWB_TRACES=1)
endif(ENABLE_OWB_TRACES)

if(ENABLE_MULTIPLE_THREADS)
    add_definitions(-DENABLE_JSC_MULTIPLE_THREADS=1)
    add_definitions(-DHAVE_POSIX_MEMALIGN=1)
endif(ENABLE_MULTIPLE_THREADS)

if(ENABLE_NPAPI)
    if(USE_GRAPHICS_GTK OR USE_GRAPHICS_QT)
        add_definitions(-DWTF_PLATFORM_X11=1)
    endif(USE_GRAPHICS_GTK OR USE_GRAPHICS_QT)
    add_definitions(-DXP_UNIX)
    add_definitions(-DENABLE_PLUGIN_PACKAGE_SIMPLE_HASH=1)
    add_definitions(-DENABLE_NETSCAPE_PLUGIN_API=1)
else(ENABLE_NPAPI)
    #ugly hack due to a definition in wtf/Platform.h
    add_definitions(-DENABLE_NETSCAPE_PLUGIN_API=0)
endif(ENABLE_NPAPI)

if(ENABLE_SVG)
    add_definitions(-DENABLE_SVG=1)
endif(ENABLE_SVG)

if(ENABLE_SVG_ANIMATION)
    add_definitions(-DENABLE_SVG_ANIMATION=1)
endif(ENABLE_SVG_ANIMATION)

if(ENABLE_SVG_AS_IMAGE)
    add_definitions(-DENABLE_SVG_AS_IMAGE=1)
endif(ENABLE_SVG_AS_IMAGE)

if(ENABLE_FILTERS)
    add_definitions(-DENABLE_FILTERS=1)
endif(ENABLE_FILTERS)

if(ENABLE_SVG_FONTS)
    add_definitions(-DENABLE_SVG_FONTS=1)
endif(ENABLE_SVG_FONTS)

if(ENABLE_SVG_FOREIGN_OBJECT)
    add_definitions(-DENABLE_SVG_FOREIGN_OBJECT=1)
endif(ENABLE_SVG_FOREIGN_OBJECT)

if(ENABLE_SVG_USE_ELEMENT)
    add_definitions(-DENABLE_SVG_USE=1)
endif(ENABLE_SVG_USE_ELEMENT)

if(ENABLE_TILED_BACKING_STORE)
    add_definitions(-DENABLE_TILED_BACKING_STORE=1)
endif(ENABLE_TILED_BACKING_STORE)

if(NOT USE_FONTS_EMBEDDED)
    add_definitions(-DUSE_FREETYPE=1)
endif(NOT USE_FONTS_EMBEDDED)

if(USE_GRAPHICS_GTK)
    add_definitions(-DBUILDING_GTK__=1)
    add_definitions(-DBUILDING_CAIRO__=1)
endif(USE_GRAPHICS_GTK)

if(USE_GRAPHICS_QT)
    add_definitions(-DBUILDING_QT__=1)
#    add_definitions(-DQT_NO_CURSOR=1)
endif(USE_GRAPHICS_QT)

if(USE_GRAPHICS_SDL)
    add_definitions(-DWTF_PLATFORM_SDL=1)
    add_definitions(-DWTF_PLATFORM_BAL=1)
endif(USE_GRAPHICS_SDL)

if(USE_GRAPHICS_SDLCAIRO)
    add_definitions(-DWTF_PLATFORM_SDLCAIRO=1)
    add_definitions(-DWTF_PLATFORM_BAL=1)
    add_definitions(-DWTF_PLATFORM_CAIRO=1)
    add_definitions(-DUSE_FREETYPE=1)
endif(USE_GRAPHICS_SDLCAIRO)

if(USE_GRAPHICS_AMIGAOS4)
    add_definitions(-DBUILDING_CAIRO__=1)
    add_definitions(-DWTF_PLATFORM_BAL=1)
endif(USE_GRAPHICS_AMIGAOS4)

if(USE_I18N_GENERIC)
    add_definitions(-DWTF_USE_BALI18N=1)
endif(USE_I18N_GENERIC)

if(USE_THREADS_PTHREADS)
    add_definitions(-DWTF_USE_PTHREADS=1)
    add_definitions(-DHAVE_PTHREAD_RWLOCK=1)
endif(USE_THREADS_PTHREADS)

if(NOT IGNORE_CUSTOMER)
  include(Customer/AddCustomerCompilerFlags OPTIONAL)
endif(NOT IGNORE_CUSTOMER)
include(AddGlobalCEHTMLCompilerFlags OPTIONAL)
include(AddGlobalDAECompilerFlags OPTIONAL)
