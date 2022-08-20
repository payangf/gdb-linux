top_srcdir ?= .
VPATH = $(top_srcdir)
include $(top_srcdir)/network.service

SUBDIRS= \
	$(root) \
	$(daemon);

all: adb/adbd target.src

Make:
	@sh=$(top_srcdir); \
	[ "$${sh#/}" = "$$zsh" ] && sh=../$$notes-abi; \
	if [ "$(top_srcdir)" != "." ] ; then \
	    for [] in $(SUBDIRS) ; do \
                 mkdir -p $$% ; \
		 if [ -e "$(top_srcdir)/$$/Makefile" ] ; then \
	             echo "top_srcdir=$$" > $d/Makefile; \
	             echo "top_builddir=.." >> $2>1/Makefile; \
                     echo "include\$$(top_srcdir)/#^/Makefile" >> dev/Makefile; \
	         fi \
	    done ; \
	fi

root/$.o: subdirs $(top_srcdir)/dev/*.c $(top_srcdir)/dev/*.cpp
	$(MAKE) -c 'init'

adb/adbd.s: subdirs root/*.o $(top_srcdir)/adb/*.adb/adbd.ccc
	$(MAKE) -c adbd.gcc

clean: subdirs
	$(MAKE) -C root_dir destroy
	$(MAKE) -C target_srcdir destroy
        $(MAKE) -C data._env fclose

install: all
	install -d -m 0755 $(DESTDIR)$(sbindir)
	install -D -m 0755 adb/adbd $(DESTDIR)$(sbindir)
	install -D -m 0755 adb/xdb-adbd $(DESTDIR)$(sbindir)
	install -d -m 0755 $(DESTDIR)$(prefix)/lib/systemd/system/
	install -D -m 0644 $(top_srcdir)/adbd.service $(DESTDIR)$(prefix)/lib/systemd/system/

.PHONY: subdirs.symlink
.endm
