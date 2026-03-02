import argparse
from .runner import run


def main():
    parser = argparse.ArgumentParser("voidproxy")
    parser.add_argument("--port", type=int, default=8080)

    args = parser.parse_args()
    run(args.port)


if __name__ == "__main__":
    main()