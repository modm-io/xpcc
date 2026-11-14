# Copyright (c) 2026, Niklas Hauser
#
# This file is part of the modm project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

# Same targets as modm/test/Makefile, only for the XPCC tests
LBUILD = $(shell which lbuild)
SCONS = scons
port ?= "auto"

define compile-test
	@$(RM) -r ../build/generated-unittest/$(1)
	$(LBUILD) -p ../build/generated-unittest/$(1) -c config/$(1).xml $(3) \
			  -C ../build/generated-unittest/$(1) build --no-log
	$(SCONS) -C ../build/generated-unittest/$(1) $(2) port=$(port)
endef

run-hosted-linux:
	$(call compile-test,hosted,run,-D":target=hosted-linux")
run-hosted-darwin:
	$(call compile-test,hosted,run,-D":target=hosted-darwin")
run-hosted-darwin-arm64:
	$(call compile-test,hosted,run,-D":target=hosted-darwin-arm64")
run-hosted-windows:
	$(call compile-test,hosted,run,-D":target=hosted-windows")

compile-mega-2560-pro:
	$(call compile-test,mega-2560-pro,size)
run-mega-2560-pro:
	$(call compile-test,mega-2560-pro,program)
