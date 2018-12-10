/*
 * ports.c
 * 
 * Copyright 2018 Alvarito050506 <donfrutosgomez@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "ports.h"
#include "types.h"

/*
 * 
 * name: outb
 * params: @port, @value
 * return: @0
 * description: Ejecuta la instrucción outb del procesador.
 * 
 */
int outb(uint16 port, byte value)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN"(port), "a"(value));
	return 0;
}

/*
 * 
 * name: inb
 * params: @port
 * return: @ret
 * description: Ejecuta la instrucción inb del procesador.
 * 
 */
byte inb(uint16 port)
{
	int ret;
	__asm__ __volatile__("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}
