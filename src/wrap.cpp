#include <pybind11/pybind11.h>
#include <iosfwd>
#include <string>

namespace pybindbug {

// C++11 scoped enum, must be fully qualified to use.
enum class FillType
{
    OuterCode= 201,
    OuterOffset = 202,
    ChunkCombinedCode = 203,
    ChunkCombinedOffset= 204,
    ChunkCombinedCodeOffset = 205,
    ChunkCombinedOffsetOffset = 206,
};

std::ostream &operator<<(std::ostream &os, const FillType& fill_type);

} // namespace contourpy


namespace py = pybind11;

PYBIND11_MODULE(_bug, m) {
    py::enum_<pybindbug::FillType>(m, "FillType",
        "Enum used for ``fill_type`` keyword argument in :func:`~pybindbug.contour_generator`.\n\n"
        "This controls the format of filled contour data returned from "
        ":meth:`~pybindbug.ContourGenerator.filled`.")
        .value("OuterCode", pybindbug::FillType::OuterCode)
        .value("OuterOffset", pybindbug::FillType::OuterOffset)
        .value("ChunkCombinedCode", pybindbug::FillType::ChunkCombinedCode)
        .value("ChunkCombinedOffset", pybindbug::FillType::ChunkCombinedOffset)
        .value("ChunkCombinedCodeOffset", pybindbug::FillType::ChunkCombinedCodeOffset)
        .value("ChunkCombinedOffsetOffset", pybindbug::FillType::ChunkCombinedOffsetOffset)
        .export_values();


}
