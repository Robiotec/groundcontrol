#!/usr/bin/env python
import os


def main():
    qrc_file = open("InstrumentValueIcons.qrc", "wt")

    qrc_file.write("<RCC>\n")
    qrc_file.write('\t<qresource prefix="/InstrumentValueIcons">\n')

    files = os.listdir(".")
    print(files)
    for filename in files:
        if filename.endswith(".svg"):
            qrc_file.write('\t\t<file alias="%s">%s</file>\n' % (filename, filename))

    qrc_file.write("\t</qresource>\n")
    qrc_file.write("</RCC>\n")

    qrc_file.close()


if __name__ == "__main__":
    main()
