/* markdown_peg.h */
#ifndef MARKDOWN_PEG_H
#define MARKDOWN_PEG_H

#include "markdown_lib.h"
#include <glib.h>

/* Information (label, URL and title) for a link. */
struct Link {
    struct Element   *label;
    char             *url;
    char             *title;
};

typedef struct Link md_link;

/* Information (label and two sources) for a media link. */
struct Media {
    struct Element   *label;
    char             *source1;
    char             *source2;
};

typedef struct Media media;

/* Union for contents of an Element (string, list, link, or media). */
union Contents {
    char             *str;
    struct Link      *link;
    struct Media     *media;
};

/* Types of semantic values returned by parsers. */
enum keys { LIST,   /* A generic list of values.  For ordered and bullet lists, see below. */
            RAW,    /* Raw markdown to be processed further */
            SPACE,
            LINEBREAK,
            ELLIPSIS,
            EMDASH,
            ENDASH,
            ENSPACE,
            APOSTROPHE,
            SINGLEQUOTED,
            DOUBLEQUOTED,
            STR,
            LINK,
            IMAGE,
            MEDIA,
            AUDIO,
            VIDEO,
            CODE,
            HTML,
            EMPH,
            STRONG,
            STRIKE,
            PLAIN,
            PARA,
            LISTITEM,
            BULLETLIST,
            ORDEREDLIST,
            H1, H2, H3, H4, H5, H6,  /* Code assumes that these are in order. */
            BLOCKQUOTE,
            SPOILERBLOCK,
            VERBATIM,
            HASHTAG,
            USERNAME,
            HTMLBLOCK,
            HRULE,
            REFERENCE,
            NOTE
          };

/* Semantic value of a parsing action. */
struct Element {
    int               key;
    union Contents    contents;
    struct Element    *children;
    struct Element    *next;
};

typedef struct Element element;

element * parse_references(char *string, int extensions);
element * parse_notes(char *string, int extensions, element *reference_list);
element * parse_markdown(char *string, int extensions, element *reference_list, element *note_list);
void free_element_list(element * elt);
void free_element(element *elt);
void print_element_list(GString *out, element *elt, int format, int exts);

#endif
