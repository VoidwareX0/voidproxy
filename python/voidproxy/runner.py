from .bindings import core_binding


def run(port: int = 8080):
    print(f"[Voidproxy] Starting on port {port}")
    core_binding.start(port)