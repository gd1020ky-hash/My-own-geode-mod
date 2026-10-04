# Auto Decorator

A Geode mod for Geometry Dash that automatically generates decoration
around an existing level layout.

## Goal

The goal is to let a creator make the gameplay first and then use:

    AUTO DECORATE

to automatically generate visual decoration without manually placing
every decorative object.

## Planned features

- Automatic block decoration
- Automatic slope decoration
- Ground and ceiling details
- Background decoration
- Glow effects
- Color matching
- Decoration variation
- Seed-based generation
- Generated-object group
- Clear generated decoration
- Multiple decoration styles

## Safety

The decorator should never intentionally modify gameplay collision.

Generated decoration will be placed in a dedicated editor group so it
can be identified and removed separately.

## Project structure

    AutoDecorator/
    ├── src/
    │   └── main.cpp
    ├── CMakeLists.txt
    ├── mod.json
    └── README.md

## Status

Early development.

The current source provides the project foundation. The procedural
decoration engine is being developed separately so it can use the
correct Geode editor APIs instead of relying on guessed functions.

## License

See LICENSE.
