import ctypes
import os

LIB_PATH = os.path.abspath(
    os.path.join(
        os.path.dirname(__file__),
        "../../../build/libvoidproxy_core.so"
    )
)

core = ctypes.CDLL(LIB_PATH)

core.vp_start.argtypes = [ctypes.c_int]
core.vp_start.restype = None


def start(port: int):
    core.vp_start(port)