#include <mbgl/map/map_options.hpp>
#include <mbgl/util/constants.hpp>

#include <cassert>

namespace mbgl {

class MapOptions::Impl {
public:
    MapMode mapMode = MapMode::Continuous;
    ViewportMode viewportMode = ViewportMode::Default;
    std::string cachePath;
    std::string assetRoot;
    uint64_t maximumSize{mbgl::util::DEFAULT_MAX_CACHE_SIZE};
    bool crossSourceCollisions = true;
};

MapOptions::MapOptions() : impl_(std::make_shared<MapOptions::Impl>()) {}
MapOptions::~MapOptions() = default;

MapOptions& MapOptions::withMapMode(MapMode mode) {
    impl_->mapMode = mode;
    return *this;
}

MapMode MapOptions::mapMode() const {
    return impl_->mapMode;
}

MapOptions& MapOptions::withViewportMode(ViewportMode mode) {
    impl_->viewportMode = mode;
    return *this;
}

ViewportMode MapOptions::viewportMode() const {
    return impl_->viewportMode;
}


MapOptions& MapOptions::withCrossSourceCollisions(bool enableCollisions) {
    impl_->crossSourceCollisions = enableCollisions;
    return *this;
}

bool MapOptions::crossSourceCollisions() const {
    return impl_->crossSourceCollisions;
}

}  // namespace mbgl
