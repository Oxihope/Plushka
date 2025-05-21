import storage as s
import operations as o

def main():
    storage = s.Storage()
    storage.load_all()
    cli = o.CLI(storage)
    cli.run()

if __name__ == "__main__":
    main()