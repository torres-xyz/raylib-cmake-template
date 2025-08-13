#pragma once

namespace constants
{
    // Inline variables have external linkage by default, so that they are visible to the linker.
    // This is necessary so the linker can de-duplicate the definitions.
    inline constexpr int screenWidth = 800;
    inline constexpr int screenHeight = 450;
}