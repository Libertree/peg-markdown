#ifndef MARKDOWN_LIB_H
#define MARKDOWN_LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif

enum markdown_extensions {
    EXT_SMART            = 0x0001,
    EXT_NOTES            = 0x0002,
    EXT_FILTER_HTML      = 0x0004,
    EXT_FILTER_STYLES    = 0x0008,
    EXT_STRIKE           = 0x0010,
    EXT_AUTOLINK         = 0x0020,
    EXT_HARD_WRAP        = 0x0040,
    EXT_NO_IMAGES        = 0x0080,
    EXT_MEDIA            = 0x0100,
    EXT_CODEBLOCK        = 0x0200,
    EXT_HASHTAGS         = 0x0400,
    EXT_USERNAMES        = 0x0800,
};

enum markdown_formats {
    HTML_FORMAT,
    LATEX_FORMAT,
    GROFF_MM_FORMAT,
    ODF_FORMAT
};

GString * markdown_to_g_string(char *text, int extensions, int output_format);
char * markdown_to_string(char *text, int extensions, int output_format);

#ifdef __cplusplus
}
#endif

/* vim: set ts=4 sw=4 : */
#endif

