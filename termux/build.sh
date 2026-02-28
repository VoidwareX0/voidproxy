#!/data/data/com.termux/files/usr/bin/bash
# Termux package build script for voidproxy
# This file goes in: voidproxy/termux/build.sh

TERMUX_PKG_HOMEPAGE=https://github.com/voidwarex0/voidproxy
TERMUX_PKG_DESCRIPTION="Universal proxy tool with SSL bypass - rootless"
TERMUX_PKG_LICENSE="MIT"
TERMUX_PKG_MAINTAINER="VoidwareX0 <voidwarex0@voidwarex0.dev>"
TERMUX_PKG_VERSION=1.0.0
TERMUX_PKG_SRCURL=https://github.com/voidwarex0/voidproxy/archive/v${TERMUX_PKG_VERSION}.tar.gz
TERMUX_PKG_DEPENDS="python, openssl"
TERMUX_PKG_PLATFORM_INDEPENDENT=true

termux_step_make_install() {
    # Install Python modules
    python setup.py install --prefix=$TERMUX_PREFIX
    
    # Install main executable
    install -Dm700 vproxy.py $TERMUX_PREFIX/bin/vproxy
    
    # Install config files
    install -Dm600 config.ini $TERMUX_PREFIX/etc/voidproxy/config
    
    # Install documentation
    install -Dm600 README.md $TERMUX_PREFIX/share/doc/voidproxy/README
}

termux_step_post_massage() {
    # Ensure no root requirements
    find . -type f -name "*.so" -exec strip {} \;
}