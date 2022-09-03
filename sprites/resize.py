#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import division

fnames = [ 'HUDsEspecials.c', 'LletresNumeros.c', 'Rates.c', 'Serps.c']

for fname in fnames:
    fin = open(fname)
    fout = open(fname+'_out', 'w')
    for line in fin:
        if line.find('\\') != -1:
            result = []
            n = len(line)
            i = 0
            next_byte = 0
            next_byte_count = 0
            while i < n:
                c = line[i]
                if c == '\\':
                    i += 1
                    c = line[i]
                    next_byte <<= 2
                    assert int(c) <= 2
                    next_byte += int(c)
                    next_byte_count += 1
                    if next_byte_count == 4:
                        result += '\\x%X'%next_byte
                        next_byte_count = 0
                        next_byte = 0

                elif c == '"' and next_byte_count:
                    while next_byte_count < 4:
                        next_byte <<= 2
                        next_byte_count += 1
                    result += '\\x%X'%next_byte

                else:
                    result.append(c)
                i += 1


            fout.write(''.join(result))
        else:
            fout.write(line)
