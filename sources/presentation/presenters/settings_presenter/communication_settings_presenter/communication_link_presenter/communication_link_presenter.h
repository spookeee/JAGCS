#ifndef COMMUNICATION_LINK_PRESENTER_H
#define COMMUNICATION_LINK_PRESENTER_H

// Internal
#include "base_presenter.h"
#include "dao_traits.h"

namespace domain
{
    class CommunicationService;
}

namespace presentation
{
    class CommunicationLinkPresenter: public BasePresenter
    {
        Q_OBJECT

    public:
        CommunicationLinkPresenter(domain::CommunicationService* service,
                                   const dao::LinkDescriptionPtr& description,
                                   QObject* parent = nullptr);

        dao::LinkDescriptionPtr description() const;

    public slots:
        void updateView();
        void setConnected(bool connected);
        void save();
        void remove();

    protected:
        void connectView(QObject* view) override;

    private:
        domain::CommunicationService* m_service;
        dao::LinkDescriptionPtr m_description;
    };
}

#endif // COMMUNICATION_LINK_PRESENTER_H
